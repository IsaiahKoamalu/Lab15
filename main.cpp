/**Lab-15
 *@author Isaiah Broderson
 */

#include <iostream>
#include <cassert>

struct Node
{
    size_t item;
    Node* next;
};

class DroneInventory
{
private:
    int numBuckets;
    Node** buckets;

public:
    DroneInventory(int numBuckets);

    /**
     * Returns true if the hash of droneID is in one of the buckets.
     */

bool contains(const std::string& droneID)
    {
        // TODO: implement
    }

    /**
     * Add the hash of droneID to the appropriate bucket.
     */
    void add(const std::string& droneID)
    {
        // TODO: implement
    }
};

void run_tests()
{
    DroneInventory inventory {3};
    inventory.add("ABC");

    assert(inventory.contains("ABC"));
    assert(!inventory.contains("ABD"));
}

int main()
{
    run_tests();

    DroneInventory inventory {50};

    // TODO: open drone-models.txt and call inventory.add() for all of the drone model numbers

    if (!inventory.contains("Z3FSHP68KQ8MR84K"))
    {
        std::cout << "That's an imposter drone!\n";
    }
    else
    {
        std::cout << "That looks like our drone! (but it isn't; something is wrong with your program)\n";
    }

    if (inventory.contains("Z3FSHP68KQ8MR84J"))
    {
        std::cout << "That's one of our drones! Here's your $1,000,000!\n"
    }
    else
    {
        std::cout << "That's not one of our drones (it actually is; something is wrong with your program)\n";
    }
}
