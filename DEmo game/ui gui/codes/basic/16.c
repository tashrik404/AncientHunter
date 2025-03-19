# include <stdio.h>

// Remove all the duplicates in the second array and then concatenate the two arrays
int main() {
    int arr[20] = {1, 2, 3, 4, 5};
    int prr[6] = {9, 8, 10, 100, 90};
    int i, j, k, m;

    // Determine the new effective length of prr after removing duplicates
    m = 5;  // Starting length of prr



    // Remove elements from prr that are present in arr
    for (i = 0; i < 5; i++) {  // Adjusted loop to run till 5 (length of arr)
        for (j = 0; j < m; j++) {  // Adjusted loop to run till m (length of prr)
            if (arr[i] == prr[j]) {
                // Shift elements to remove the matched element in prr
                for (k = j; k < m-1 ; k++) {
                    prr[k] = prr[k + 1];
                }
                m--;  // Decrease the effective length of prr

            }
        }
    }

    // Concatenate unique elements of prr to arr
    for (i = 5, j = 0; j < m; i++, j++) {
        arr[i] = prr[j];
    }

    // Print the resulting arr array
    for (i = 0; i < 5 + m; i++) {  // Print only the filled part of arr
        printf("%d ", arr[i]);
    }

    return 0;
}
