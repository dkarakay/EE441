#define SIZE_OF_HASH_TABLE 65536

class HT_Item
{

public:
    Matrix key;
    long value;
};

class HashTable
{

private:
    HT_Item* table[SIZE_OF_HASH_TABLE];
    int count = 0;
public:
    HashTable();
    int hash(Matrix M);
    bool key_exists(Matrix A);
    long search(Matrix A);
    void insert(Matrix A, long detA);
    void print_table();

};

HashTable::HashTable()
{
    for(int i=0; i<SIZE_OF_HASH_TABLE; i++)
    {
        table[i] = NULL;
    }
    count = 0;
}

int HashTable::hash(Matrix M)
{
    long hash_value = M.getSize();
    int size = M.getSize();

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            hash_value += 61 + M.getElement(i,j);
            //cout << hash_value<< endl;
        }
    }

    hash_value %= SIZE_OF_HASH_TABLE;
    //cout << hash_value << endl;

    return hash_value;
}

bool HashTable::key_exists(Matrix A)
{
    int hash_val = hash(A);
    int temp_val = hash_val;
    while(temp_val < SIZE_OF_HASH_TABLE)
    {
        if(table[temp_val] == NULL)
        {
            return false;
        }

        else if(A.compareMatrices(table[temp_val]->key)==0)
        {
            return true;
        }

        temp_val+=1;
    }

    temp_val = 0;
    while (temp_val < hash_val)
    {
        if(table[temp_val] == NULL)
        {
            return false;
        }

        else if(A.compareMatrices(table[temp_val]->key)==0)
        {
            return true;
        }
        temp_val +=1;
    }

    return false;
}

long HashTable::search(Matrix A)
{
    int hash_val = hash(A);

    // Check till SIZE_OF_HASH_TABLE
    int temp_val = hash_val;
    while(temp_val < SIZE_OF_HASH_TABLE)
    {
        if(table[temp_val]!= NULL)
        {
            if(A.compareMatrices(table[temp_val]->key)==0)
            {
                return table[temp_val]->value;
            }
        }
        temp_val +=1;
    }


    // Start from 0 till hash_val
    temp_val = 0;
    while (temp_val < hash_val)
    {
        if(table[temp_val]!= NULL)
        {
            if(A.compareMatrices(table[temp_val]->key)==0)
            {
                return table[temp_val]->value;
            }
        }
        temp_val +=1;
    }

    return -1111;

}


void HashTable::insert(Matrix A, long detA)
{
    HT_Item* ht_item = new HT_Item();
    ht_item->key   = A;
    ht_item->value = detA;

    //cout << "KEY EXISTS: " <<key_exists(A) << endl;


    if(!key_exists(A))
    {
        int hash_val = hash(A);
        int temp_val = hash_val;

        while(temp_val < SIZE_OF_HASH_TABLE)
        {
            if(table[temp_val]== NULL)
            {
                table[temp_val] = ht_item;
                count +=1;
                return;
            }
            temp_val +=1;
        }


        temp_val = 0;
        while(temp_val < hash_val)
        {
            if(table[temp_val]== NULL)
            {
                table[temp_val] = ht_item;
                count +=1;
                return;
            }
            temp_val +=1;
        }
    }
    //cout << search(A) << endl;

}

void HashTable::print_table()
{
    for(int i =0; i<SIZE_OF_HASH_TABLE; i++)
    {
        if(table[i]!= NULL)
        {
            cout << "Hash: "<< i << ", Det: " << table[i]->value << endl;
        }
    }

}
