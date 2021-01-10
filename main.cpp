// Array ADT

# include<stdio.h>
# include <stdlib.h>

// This structure is a basic array declaration
struct Array{
    int *array;
    // Pointer to the array in heap

    int size_of_array;
    // The total size of the array

    int length_of_array;
    // The number used in the array



};

// Function to insert elements at the end of the array
/* Here we have to modify the array therefore
 * we are using call by address */

void append (struct Array *arr, int value_to_enter){
    if (arr->length_of_array< arr->size_of_array){
        arr->array[arr->length_of_array++ ] = value_to_enter ;


    }


}

void insert (struct Array *arr , int value_to_enter, int position){

    if (arr->length_of_array< arr->size_of_array){
        for (int i = arr->length_of_array ; i > position ; i -- ){
            arr->array[i]=arr->array[i-1];

        }
        arr->array[position]=value_to_enter;

        // To increase the length of the array
        arr->length_of_array++;


    }
}

// Function to delete an element from the array
void delet (struct Array *arr , int position ){

    // variable to store the value that we have deleted
    int deleted_value ;

    if ( position > 0 && position < arr->length_of_array){
        deleted_value = arr->array[position];
        for (int i = position ; i < arr-> length_of_array ; i ++){
            arr->array[i]=arr->array[i+1];
        }
        arr->length_of_array--;

    }

    else {
        printf("The index is invalid");
    }



}

// Function to do linear search in an array
int linear_search (struct Array *arr , int key ){

    // Key is the element that we want to search

    for (int i = 0 ; i < arr->length_of_array; i++ ){
        if (key == arr->array[i]){
            return i ;
        }

    }
    return -1 ;
}

// Function to do binary search on the array
// Binary search is always applied on an sorted array
int binary_search (struct Array *arr , int key ){
    int first , last , mid ;
    first = 0 ;
    last = arr->length_of_array ;

    while (first < last ){
        mid = (first + last )/2 ;
        if (key == arr->array[mid] ){
            return mid ;
        }

        else if (key > arr->array[mid] ){
            first = mid + 1 ;


        }

        else
            last = mid - 1 ;



    }


    return -1;
}

// Reversing an array using an extra array

int reverse_1(struct Array *arr ){
    int *new_array ;
    int i , j ;
    new_array = (int * )malloc (arr->length_of_array*sizeof(int));
    for (j = arr->length_of_array -1 , i =0  ; j > 0 ; i++ , j -- ){
        new_array[i] = arr->array[j];
    }

    for (i=0 ; i < arr->length_of_array ; i ++ ){
        printf("%d", new_array[ i]);
        printf(" ");
    }

    return 0 ;
}

// Function to reverse an array without using an extra array
int reverse_2(struct Array *arr){
    int i , j ,temp ;
    for ( i = 0 , j = arr->length_of_array - 1 ; i <= j ; i ++ , j-- ){

        // variable swapping
        temp = arr->array[i];
        arr->array[i] = arr->array[ j ];
        arr-> array[j] = temp ;

    }

    printf("The reversed array ");
    for (i = 0 ; i < arr-> length_of_array ; i ++ ){
        printf("%d", arr->array[i]);
        printf(" ");
    }

    return 0 ;
}

// Function to return the value at a particular index in an array
int get_value (struct Array *arr , int index ){
    if (index>0 && index < arr->length_of_array){
        return arr->array[index];
    }

    return -1;

}

// Function to find the maximum value in an array
int max (struct Array *arr ){
    int max = arr-> array[0];
    for (int i =0 ; i< arr->length_of_array; i++){
        if (arr-> array[i]>max){
            max = arr-> array[i];

        }

    }
    return max ;
}

// Function to set a particular at a particular index
int set (struct Array *arr, int value_to_set, int index ){
    if (index > 0 && index < arr->length_of_array){
        arr->array[index] = value_to_set;

    }

    else {
        return -1;
    }
    printf("The new array is ");
    for (int i =0 ; i < arr->length_of_array ; i ++ ){
        printf("%d",arr->array[i]);
        printf(" ");
    }
    return 0 ;

}

// Function to insert an element in a sorted array
int insertion_in_sorted_array(struct Array *arr, int key) {
    // Here key is the number to inserted in the array
    if (arr->length_of_array < arr->size_of_array) {
        int i = arr->length_of_array-1 ;
        while (arr->array[i]>key){
            arr->array[i+1] = arr->array[i];
            i--;

        }
        arr->array[i+1] = key ;
        arr->length_of_array ++ ;
    }

    return 0 ;

}

// Fucntion to check wheather the array is sorted or not
int sorted_array ( struct Array arr ){
    if ( arr.length_of_array < arr.size_of_array){
        int i =0 ;

        while (i < arr.length_of_array-1){
            if (arr.array[i+1]>arr.array[i]){
                i++;
            }


        }
        if (i== (arr.length_of_array)-1) {
            printf("The array is sorted ");

        }

        else {
            printf("The array is not sorted ");

        }

    }
    return 0 ;

}

// Function to shift all the negatives element on one side and positive on others
int pos_neg_shift (struct Array *arr ){
    int i = 0 ;
    int j = arr->length_of_array-1;
    while(i<j){
        if (arr->array[i]<0){
            i++;

        }

        if (arr->array[j]>= 0 ){
            j--;

        }

        if (arr->array[i] > 0 && arr->array[j] <= 0 ){
            int temp = arr->array[i];
            arr->array[i] = arr->array[j];
            arr->array[j] = temp ;
        }
    }
    return 0 ;
}



// Function to find the single missing element in the sorted array
// 1) First Way
int find_missing(struct Array arr){
    // The array is starting from 1 and the array is of first n natural number

    int i = 0 ;

    while ( i < arr.length_of_array){
        if ( arr.array[i] == i +1){
            i++;

        }
        else {
            printf("The missing number is ");
            printf("%d", i+1);
            break;
        }

    }
    return 0 ;



    return 0 ;
}

// 2) Second Way
void find_missing_2(struct Array arr){
    // In this function we will use the method of sum of first n number

    int sum_to_be ;
    // Variable to store the sum of first n natural numbers

    sum_to_be = ( arr.length_of_array * (arr.length_of_array + 1) )/2;

    int sum_of_array=0;
    // Variable to store the sum of the elements store in the array

    for (int i =0 ; i<arr.length_of_array-1;i++){
        sum_of_array = sum_of_array + arr.array[i];

    }

    printf("The missing number is ");
    printf("%d", sum_to_be - sum_of_array );



}

// This function is used to find more than one missing elements in an array
// Sorted array
int find_many_missing(struct Array arr){

    int i =0 ;

    // For traversing through the whole array
    printf("The missing elements are ");
    while (i < arr.length_of_array-1){
        // Checking the difference between consecutive 2 numbers
        if (arr.array[i+1] - arr.array[i] !=1){
            // For printing the missing number
            for (int j = arr.array[i] +1  ; j<arr.array[i+1] ; j++ ){
                printf("%d", j );
                printf(" ");
            }

        }
        i++;
    }
    // The total time complexity of the function is order of n
    // because the other loop is just for printing the elements
    // and it running only a few times


    return 0 ;
}

// Function to find the duplicates in an sorted array
int finding_duplicates(struct Array arr){

   int i =0 ;
   int j ;
   // Loop to traverse all over the array
   while (i < arr.length_of_array -1 ){
       if (arr.array[i] == arr.array[i+1]){
           j = i + 1 ;
           // Loop to count the number of times a number has appeared in the array
           while (arr.array[j] == arr.array[j+1]){
               j ++;


           }

           // The number of times a variable has appeared in the array is equal to j - i + 1
           printf("The number %d has appeared %d times ", arr.array[i] , j-i + 1  );
           printf("\n");
           i = j ;

       }

       i++;






   }
   return 0 ;
}



// Finding duplicates in a unsorted array
int finding_in_unsorted(struct Array arr ) {
// In this function we are coverting the duplicate to -1

    // For traversing through the array
   for (int i =0 ; i < arr.length_of_array-1 ; i ++){

       // The variable to store the frequency of repeated number
       int count = 1 ;

       int j = i + 1 ;
       // We will make the repeated the variable as -1 so that it should't be counted again
       if (arr.array[i] != -1 ) {

           // Loop for traversing through the array to find the duplicates in it
           while (j < arr.length_of_array ) {
               if (arr.array[i] == arr.array[j]) {

                   // Making the repeated values as -1
                   arr.array[j] = -1;

                   // Increamenting the count one by one
                   count = count + 1;

               }
               j++;


           }
           // Printing the number and it's frequency
           printf("The number %d is appearing %d times ", arr.array[i], count);
           printf("\n");
       }





   }
   return 0 ;
}

// Finding sum equal to k in a sorted list
int sum_in_sorted(struct Array arr , int key ){
    int i = 0 ;
    int j = arr.length_of_array-1 ;

    // taking two variables i and j starting from the front and end
    while (i < arr.length_of_array-1 && j > i  ){
        if (arr.array[i] + arr.array[j] > key ){
            j--;

        }

        if (arr.array[i] + arr.array[j] < key ){
            i ++ ;

        }

        if ( arr.array [i] + arr.array [j] == key ){
            printf("The numbers with the sum %d are %d and %d ", key, arr.array[i] , arr.array[j]);
            printf("\n");
            i++;
            j--;
        }





    }
    return 0 ;
}

// Finding max and min in a single scan
int finding_max_min(struct Array arr ){
    int max = arr.array[0];
    int min = arr.array[0];
    for (int i =0 ; i < arr.length_of_array-1 ; i ++ ){

        if (arr.array[i] > max ){
            max = arr.array[i] ;

        }

        if (arr.array[i] < min ){
            min = arr.array[i];
        }


    }

    printf("The max in the list is %d and min in the list is %d" , max , min );

}

// Finding the elements having sum equal to k
int sum_in_unsorted(struct Array arr, int key){
    // Here key is the total sum of the number we need

    // Loop for traversing through the array
    for (int i = 0 ; i < arr.length_of_array -1 ; i++ ){

        // We are making the value equal to -1 if it is checked
        if (arr.array[i] != -1 ) {

            // Variable to store the value of the number of the j loop
            int repeat ;

            for (int j = i + 1; j < arr.length_of_array; j++) {

                // Condition for making the number as -1
                if (arr.array[j]==repeat ){
                    arr.array[j] = -1 ;
                }

                if (arr.array[j]==arr.array[i]){
                    arr.array[j]= -1 ;
                }


                // Checking the sum of the numbers from both the list i and j
                if (arr.array[i] + arr.array[j] == key) {
                    repeat = arr.array[j];
                    arr.array[j] = -1;
                }






            }

            // Printing only when the condition is satisfied otherwise the last value of repeat will be printed
            // twice and the last pair will be wrong
            if (arr.array[i] + repeat == key && repeat > 0 ) {
                printf("The number with sum %d are %d and %d ", key, arr.array[i], repeat);
                printf("\n");
            }
        }

    }
    return 0 ;

}








// Function to display all the elements of the array
/* Here we are not modifying the array therefore
 * we are call by value */

void display (struct Array arr ){
    printf("The elements of the array are ");

    for (int i =0 ; i < arr.length_of_array ; i++){
        printf("%d", arr.array[i]);
        printf(" ");



    }

}

int main (){

    // Declaration of a struct Array type variable
    // Array with values of n natural numbers
    struct Array arr;


    // Array with values taken from the programmer
    struct Array arr_1;
    arr_1.size_of_array;
    arr_1.length_of_array=10;
    arr_1.size_of_array =20 ;

    arr_1.array = (int * )malloc(10*sizeof(int));

    arr_1.array[0]=1 ;
    arr_1.array[1]=2;
    arr_1.array[2]=3;
    arr_1.array[3]=5;

    arr_1.array[4]=6;
    arr_1.array[5]=7 ;
    arr_1.array[6]=8;
    arr_1.array[7]=9;
    arr_1.array[8]=10;

    arr_1.array[9]=12;





    // Displaying of output starts here
    printf("Enter the size of the array");
    scanf("%d",&arr.size_of_array);

    // Creating an array in heap of type struct Array
    arr.array = (int *)malloc(arr.size_of_array*sizeof(int));

    printf("Enter number of elements you want in the array");
    scanf("%d", &arr.length_of_array);

    // Loop for initializing the array
    for (int i =0 ; i < arr.length_of_array ; i++){
        arr.array[i] = i;


    }


    display(arr_1);

    printf(" \n");


    insertion_in_sorted_array(&arr_1, 6);
    display(arr_1);
    return 0 ;
}

