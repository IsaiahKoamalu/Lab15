/**Lab-15
 *@author Isaiah Broderson
 */

#include <iostream>
#include <string>
#include <fstream>

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
    explicit DroneInventory(int numBuckets) : numBuckets(numBuckets) {
        buckets = new Node*[numBuckets];
        for (int i = 0; i < numBuckets; ++i) {
            buckets[i] = nullptr;
        }
    };

    /**
     * Returns true if the hash of droneID is in one of the buckets.
     */

bool contains(const std::string& droneID) {
        size_t hashValue = std::hash<std::string>{}(droneID);
        int index = hashValue % numBuckets;

        Node* current = buckets[index];
        while (current != nullptr) {
            if (current->item == hashValue){return true;}
            current = current->next;
        }
        return false;
    }

    /**
     * Add the hash of droneID to the appropriate bucket.
     */
    void add(const std::string& droneID){
        if (contains(droneID)) return;

        size_t hashValue = std::hash<std::string>{}(droneID);
        int index = hashValue % numBuckets;

        Node* newNode = new Node{hashValue, buckets[index]};
        buckets[index] = newNode;
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

    DroneInventory inventory {1000};

    std::ifstream file("drone-models.txt");
    if (!file) {
        std::cerr << "ERROR: Problem opening file\n";
        return 1;
    }

    std::string droneID;
    while (file >> droneID) {
        inventory.add(droneID);
    }

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
        std::cout << "That's one of our drones! Here's your $1,000,000!\n";
    }
    else
    {
        std::cout << "That's not one of our drones (it actually is; something is wrong with your program)\n";
    }
}
