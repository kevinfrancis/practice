#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vector(vector<T> &v)
{
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}


/**
 * Partition an array of elements using a pivot,
 * such that the result array looks like
 * [elements < pivot ]  [elements == pivot] [elements > pivot]
 */
void partition_naive(int pivot_index, vector<int> &v)
{
    int pivot = v[pivot_index];

    int smaller = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < pivot) {
            swap(v[i], v[smaller++]);
        }
    }

    int larger = v.size() - 1;
    for (int j = larger; j >= 0 && v[j] >= pivot; j--) {
        if (v[j] > pivot) {
            swap(v[j], v[larger--]);
        }
    }
}


/**
 * single pass approach
 *
 * pivot = 1  (S: Smaller, E: Equal, L:Larger, ?: Unclassified)
 * 5 1 0 0 1 3
 * ? ? ? ? ? ?
 *
 * 3 1 0 0 1 5
 * ? ? ? ? ? L
 *
 * 1 1 0 0 3 5
 * ? ? ? ? L L
 *
 * 1 1 0 0 3 5
 * E ? ? ? L L
 *
 * 1 1 0 0 3 5
 * E E ? ? L L
 *
 * 0 1 1 0 3 5
 * S E E ? L L
 *
 * 0 0 1 1 3 5
 * S S E E L L
 */
void partition(int pivot_index, vector<int> &v)
{
    int start = 0;               // Start of unclassified range
    int end = v.size() - 1;      // End of unclassified range
    int smaller = 0;             // Next index to write the smaller value
    int pivot = v[pivot_index];

    // Process until there are no more unclassified items
    while (start <= end) {
        if (v[start] > pivot) {
            swap(v[start], v[end--]);
        } else if (v[start] == pivot) {
            start++;
        } else { /* v[start] < pivot */
            swap(v[start++], v[smaller++]);
        }
    }
}


/**
 * Variant exercise of the partition algorithm
 */
typedef enum {
    FIRST_COLOR,
    RED = FIRST_COLOR,
    BLUE,
    GREEN,
    YELLOW,
    NUM_COLORS
} Color;

void partition_colors(vector<Color> &v)
{
    int completed = -1;
    
    for (int c = FIRST_COLOR; c < NUM_COLORS; c++) {
        // Traverse from right to left.  Move matching color to left side
        int i = v.size() - 1;
        while (i > completed) {
            if (v[i] == c) {
                swap(v[i], v[++completed]);
            } else {
                i--;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int a[] = {5,1,3,2,1,3,2,5,6,1,4,5,1,3};
    //int a[] = {1,4,5};
    int pivot_index = stoi(argv[1]);
    vector<int> v(a, a + sizeof(a)/sizeof(a[0]));

    print_vector(v);
    partition(pivot_index, v);
    print_vector(v);

    Color colors[] = {RED, BLUE, GREEN, YELLOW, BLUE, RED,
                      YELLOW, RED, GREEN, YELLOW, GREEN, YELLOW,
                      GREEN, BLUE, RED, BLUE, GREEN};
    vector<Color> color_vector(colors, colors + sizeof(colors)/sizeof(colors[0]));
    print_vector<Color>(color_vector);
    partition_colors(color_vector);
    print_vector<Color>(color_vector);
}
