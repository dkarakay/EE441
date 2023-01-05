#define SIZE_OF_HASH_TABLE 65536

// Class for HT_ITEM
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

// Construct HashTable with NULL elements
HashTable::HashTable()
{
    for(int i=0; i<SIZE_OF_HASH_TABLE; i++)
    {
        table[i] = NULL;
    }
    count = 0;
}

// Hash function to determine the address for HashTable
int HashTable::hash(Matrix M)
{
    long hash_value = M.getSize();
    int size = M.getSize();

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            // Determine hash value
            hash_value = (61*hash_value + M.getElement(i,j));

            // Take modulo to limit the output between 0 and 65536
            hash_value %= SIZE_OF_HASH_TABLE;

        }
    }

    hash_value %= SIZE_OF_HASH_TABLE;

    return hash_value;
}

// Check if key exists inside of Table
bool HashTable::key_exists(Matrix A)
{
    // Get Hash value
    int hash_val = hash(A);
    int temp_val = hash_val;

    // Start from hash value to the end of table
    // Trying to put the value to HashTable
    while(temp_val < SIZE_OF_HASH_TABLE)
    {
        // If we found NULL value, we can say that key does not exist
        if(table[temp_val] == NULL)
        {
            return false;
        }

        // If we found exact value, return true
        else if(A==(table[temp_val]->key))
        {
            return true;
        }

        temp_val+=1;
    }

    // Start from 0 to hash value
    // Trying to put the value to HashTable
    temp_val = 0;
    while (temp_val < hash_val)
    {
        // If we found NULL value, we can say that key does not exist
        if(table[temp_val] == NULL)
        {
            return false;
        }

        // If we found exact value, return true

        else if(A==(table[temp_val]->key))
        {
            return true;
        }
        temp_val +=1;
    }

    return false;
}

// Search HashTable to find the value of key
long HashTable::search(Matrix A)
{
    int hash_val = hash(A);

    // Start from hash value to the end of table
    // Trying to put the value to HashTable
    int temp_val = hash_val;
    while(temp_val < SIZE_OF_HASH_TABLE)
    {
        if(table[temp_val]!= NULL)
        {
            if(A==(table[temp_val]->key))
            {
                return table[temp_val]->value;
            }
        }
        temp_val +=1;
    }


    // Start from 0 to hash value
    // Trying to find the value inside HashTable
    temp_val = 0;
    while (temp_val < hash_val)
    {
        if(table[temp_val]!= NULL)
        {
            if(A==(table[temp_val]->key))
            {
                return table[temp_val]->value;
            }
        }
        temp_val +=1;
    }

    // Error
    return -1111;

}

// Insert function
void HashTable::insert(Matrix A, long detA)
{
    // Create new HT_Item dynamically
    HT_Item* ht_item = new HT_Item();

    // Put required values
    ht_item->key   = A;
    ht_item->value = detA;

    // If key is not found
    if(!key_exists(A))
    {
        // Calculate Hash
        int hash_val = hash(A);
        int temp_val = hash_val;

        // Start from hash value to the end of table
        // Trying to put the value to HashTable
        while(temp_val < SIZE_OF_HASH_TABLE)
        {
            if(table[temp_val]== NULL)
            {
                // Put HT_Item new to HashTable
                table[temp_val] = ht_item;

                // Increment count
                count +=1;
                return;
            }
            temp_val +=1;
        }


        // Start from 0 to hash value
        // Trying to find the value inside HashTable
        temp_val = 0;
        while(temp_val < hash_val)
        {
            if(table[temp_val]== NULL)
            {
                // Put HT_Item new to HashTable
                table[temp_val] = ht_item;

                // Increment count
                count +=1;
                return;
            }
            temp_val +=1;
        }
    }

}

// Print HashTable
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
