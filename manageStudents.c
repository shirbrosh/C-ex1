//
// Created by shir2 on 10/11/2019.
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define FIELD_LENGTH 41
#define FAIL -1
#define SUCCESS_MAIN 0
#define SUCCESS 1
#define SPACE 32
#define HYPHEN 45
#define MAX_STUDENT 5000
#define MAX_INPUT 151
#define SIZE_ARRAY_MERGE 2500
#define MAX_AGE 120
#define MIN_AGE 18
#define MAX_GRADE 100
#define MIN_GRADE 0
#define ID_LENGTH 10
#define BEST "best"
#define MERGE "merge"
#define QUICK "quick"
#define INPUT_MSG "Enter student info. To exit press q, then enter\n"
#define REGEX_INPUT "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t"
#define LINE_ERROR "in line %d\n"
#define ID_ERROR "ERROR: your id input is invalid. It should be a 10 digit number, which does "\
"not start with a zero\n"
#define NAME_ERROR "ERROR: your name input is invalid. It should contain only letters(lower or "\
"upper), space or '-' sign\n"
#define GRADE_ERROR "ERROR: your grade input is invalid. It should be an integer between 0 to 100\n"
#define AGE_ERROR "ERROR: your age input is invalid. It should be an integer between 18 to 120\n"
#define COUNTRY_ERROR "ERROR: your country input is invalid. It should contain only letters(lower "\
"or upper) or '-' sign\n"
#define CITY_ERROR "ERROR: your city input is invalid. It should contain only letters(lower or "\
"upper) or '-' sign\n"
#define ARGUMENT_MSG "USAGE: you should enter only one argument from the following:\n1) best\n2) "\
"merge\n3) quick"
#define BEST_STUDENT_MSG "best student info is: %s\t%s\t%d\t%d\t%s\t%s\t\n"
#define MERGE_QUICK_OUT "%s\t%s\t%d\t%d\t%s\t%s\t\n"

/**
 * The student struct
 */
typedef struct Student
{
    char id[FIELD_LENGTH];
    char name[FIELD_LENGTH];
    int grade;
    float age;
    char country[FIELD_LENGTH];
    char city[FIELD_LENGTH];
} Student;

/**
 * This method checks if the string input contains only numbers
 * @param string_num - the input as string
 * @return Fail= -1 if the string input contains chars that are not numbers
 *         SUCCESS= 1 if the the string input contains only numbers
 */
int onlyDigits(char *string_num)
{
    for (
            size_t i = 0; i < strlen(string_num); i++)
    {
        if (isdigit(string_num[i]) == 0)
        {
            return FAIL;
        }
    }
    return SUCCESS;
}

/**
 * This function checks if the student's id input received by the user is valid
 * @param id- the student's id input received by the user
 * @param new_student- the Student struct object that will receive the input id-if valid
 * @return  Fail= -1 if the id is invalid
 *         SUCCESS= 1 if the id is valid and was updated to the Student object
 */
int checkId(char *id, Student *new_student)
{
    //check if the input starts with a zero or contains more or less then 10 digits
    size_t id_length = strlen(id);
    if (id[0] == 0 || id_length != ID_LENGTH)
    {
        printf(ID_ERROR);
        return FAIL;
    }
    //check if the input contains only digits
    if (onlyDigits(id) == FAIL)
    {
        printf(ID_ERROR);
        return FAIL;
    }
    strcpy(new_student->id, id);
    return SUCCESS;
}

/**
 * This function checks if the student's name input received by the user is valid
 * @param name- the student's name input received by the user
 * @param new_student- the Student struct object that will receive the input name-if valid
 * @return  Fail= -1 if the name is invalid
 *         SUCCESS= 1 if the name is valid and was updated to the Student object
 */
int checkName(char *name, Student *new_student)
{
    //checks if a name input was given
    if (strlen(name) == 0)
    {
        printf(NAME_ERROR);
        return FAIL;
    }
    //checks if all the characters are only letters(lower or upper), space or '-' sign
    for (
            size_t i = 0; i < strlen(name); i++)
    {
        if (isalpha(name[i]) == 0 && (name[i] != SPACE && name[i] != HYPHEN))
        {
            printf(NAME_ERROR);
            return FAIL;
        }
    }
    strcpy(new_student->name, name);
    return SUCCESS;
}

/**
 * This function checks if the student's grade input received by the user is valid
 * @param grade- the student's grade input received by the user
 * @param new_student- the Student struct object that will receive the input grade-if valid
 * @return  Fail= -1 if the grade is invalid
 *         SUCCESS= 1 if the grade is valid and was updated to the Student object
 */
int checkGrade(char *grade, Student *new_student)
{
    //checks if a grade input was given and if the grade contains only numbers
    if (onlyDigits(grade) == FAIL || strlen(grade) == 0)
    {
        printf(GRADE_ERROR);
        return FAIL;
    }
    //convert to int and checks if the number is between 0 to 100
    int int_grade;
    sscanf(grade, "%d", &int_grade);
    if (int_grade < MIN_GRADE || int_grade > MAX_GRADE)
    {
        printf(GRADE_ERROR);
        return FAIL;
    }
    new_student->grade = int_grade;
    return SUCCESS;
}

/**
 * This function checks if the student's age input received by the user is valid
 * @param age- the student's age input received by the user
 * @param new_student- the Student struct object that will receive the input age-if valid
 * @return  Fail= -1 if the age is invalid
 *         SUCCESS= 1 if the age is valid and was updated to the Student object
 */
int checkAge(char *age, Student *new_student)
{
    //checks if a age input was given and if the grade contains only numbers
    if (onlyDigits(age) == FAIL || strlen(age) == 0)
    {
        printf(AGE_ERROR);
        return FAIL;
    }

    //convert to float and checks if the number is between 18 to 120
    float float_age;
    sscanf(age, "%f", &float_age);
    if (float_age < MIN_AGE || float_age > MAX_AGE)
    {
        printf(AGE_ERROR);
        return FAIL;
    }
    new_student->age = float_age;
    return SUCCESS;
}

/**
 * This function checks if the student's country input received by the user is valid
 * @param country- the student's country input received by the user
 * @param new_student- the Student struct object that will receive the input country-if valid
 * @return  Fail= -1 if the country is invalid
 *         SUCCESS= 1 if the country is valid and was updated to the Student object
 */
int checkCountry(char *country, Student *new_student)
{
    //checks if a country input was given
    if (strlen(country) == 0)
    {
        printf(COUNTRY_ERROR);
        return FAIL;
    }

    //checks if all the characters are only letters(lower or upper) or '-' sign
    for (
            size_t i = 0; i < strlen(country); i++)
    {
        if (isalpha(country[i]) == 0 && country[i] != HYPHEN)
        {
            printf(COUNTRY_ERROR);
            return FAIL;
        }
    }
    strcpy(new_student->country, country);
    return SUCCESS;
}

/**
 * This function checks if the student's city input received by the user is valid
 * @param city- the student's country input received by the user
 * @param new_student- the Student struct object that will receive the input city-if valid
 * @return  Fail= -1 if the city is invalid
 *         SUCCESS= 1 if the city is valid and was updated to the Student object
 */
int checkCity(char *city, Student *new_student)
{
    //checks if a city input was given
    if (strlen(city) == 0)
    {
        printf(CITY_ERROR);
        return FAIL;
    }

    //checks if all the characters are only letters(lower or upper) or '-' sign
    for (
            size_t i = 0; i < strlen(city); i++)
    {
        if (isalpha(city[i]) == 0 && city[i] != HYPHEN)
        {
            printf(CITY_ERROR);
            return FAIL;
        }
    }
    strcpy(new_student->city, city);
    return SUCCESS;
}

/**
 * This function finds and prints the best student from the given student array, according to
 * the formula- grade/age.
 * @param student_arr- the student array from which the function finds the best student
 * @param amount_student the amount of students in the array
 */
void findBestStudent(Student *student_arr, int amount_student)
{

    //initialize the best student as the first as default
    Student best_student = student_arr[0];
    float best_achievement = student_arr[0].grade / student_arr[0].age;

    //loop over the rest of the students and check if the best student is not the first student
    for (
            int i = 1; i < amount_student; i++)
    {
        float achievement = student_arr[i].grade / student_arr[i].age;
        if (achievement > best_achievement)
        {
            best_achievement = achievement;
            best_student = student_arr[i];
        }
    }
    printf(BEST_STUDENT_MSG, best_student.id, best_student.name, best_student.grade,
           (int) best_student.age,
           best_student.country, best_student.city);
}

/**
 * This function operates the parsing of the users input
 * @param count_row- the number of the users input row (the amount of times the user tried to
 *      enter an input
 * @param amount_student- the amount of students in the students array- the amount of valid inputs
 * @param student_arr - the student objects array
 */
void parser(int *count_row, int *amount_student, Student *student_arr)
{
    (*count_row) = -1;
    (*amount_student) = 0;
    Student new_student;
    char id[FIELD_LENGTH];
    char name[FIELD_LENGTH];
    char grade[FIELD_LENGTH];
    char age[FIELD_LENGTH];
    char country[FIELD_LENGTH];
    char city[FIELD_LENGTH];
    char input[MAX_INPUT];
    printf(INPUT_MSG);
    fgets(input, MAX_INPUT, stdin);

    //loop and process inputs until the user enters "q"
    while (strcmp(input, "q\n") != 0 && strcmp(input, "q\r\n") != 0)
    {
        (*count_row)++;
        sscanf(input, REGEX_INPUT, id, name, grade, age, country, city);

        //checks if there is an invalid field and prints the matching error, using the matching
        // checking functions
        if (checkId(id, &new_student) == FAIL || checkName(name, &new_student) == FAIL ||
            checkGrade(grade, &new_student) == FAIL || checkAge(age, &new_student) == FAIL ||
            checkCountry(country, &new_student) == FAIL || checkCity(city, &new_student) == FAIL)
        {
            printf(LINE_ERROR, (*count_row));
            printf(INPUT_MSG);
            fgets(input, MAX_INPUT, stdin);
            continue;
        }

        //all the given fields were valid, update the student array
        student_arr[(*amount_student)] = new_student;
        (*amount_student)++;
        printf(INPUT_MSG);
        fgets(input, MAX_INPUT, stdin);
    }
}

/**
 * This function operates the task of finding the best student from the given students
 */
void best()
{
    Student student_arr[MAX_STUDENT];
    int count_row;
    int amount_student;
    parser(&count_row, &amount_student, student_arr);
    if (amount_student > 0)
    {
        findBestStudent(student_arr, amount_student);
    }
}


/**
 * This function merges two sub arrays of a given array (student_arr) according to the students
 * grade
 * @param student_arr- the array from which the sub arrays are taking
 * @param left- the index in the student_arr from which the first sub array begins
 * @param middle- the index of the middle of student_arr which is the end of the first sub array and the beggining of the
 *      second sub array
 * @param right- the index in the student_arr that ends the second sub array
 */
void merge(Student student_arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    //create temp arrays and copy the data from student_arr
    Student L[SIZE_ARRAY_MERGE], R[SIZE_ARRAY_MERGE];
    for (
            i = 0; i < n1; i++)
    {
        L[i] = student_arr[left + i];
    }
    for (
            j = 0; j < n2; j++)
    {
        R[j] = student_arr[middle + 1 + j];
    }

    // merge the temp arrays back into student_arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i].grade <= R[j].grade)
        {
            student_arr[k] = L[i];
            i++;
        }
        else
        {
            student_arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] and R[], if there are any
    while (i < n1)
    {
        student_arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        student_arr[k] = R[j];
        j++;
        k++;
    }
}


/**
 * This function operates the merge sort technique
 * @param student_arr the array to sort
 * @param left - the left index of the sub array of student_arr to be sorted
 * @param right- the right index of the sub array of student_arr to be sorted
 */
void mergeSort(Student student_arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(student_arr, left, middle);
        mergeSort(student_arr, middle + 1, right);
        merge(student_arr, left, middle, right);
    }
}

/**
 * This function operates the task of sorting the students array by grades using merge sort
 */
void sortByGrade()
{
    Student student_arr[MAX_STUDENT];
    int count_row;
    int amount_student;
    parser(&count_row, &amount_student, student_arr);
    if (amount_student > 1)
    {
        mergeSort(student_arr, 0, amount_student - 1);
    }
    for (
            int i = 0; i < amount_student; i++)
    {
        printf(MERGE_QUICK_OUT, student_arr[i].id, student_arr[i].name, student_arr[i].grade,
               (int) student_arr[i].age,
               student_arr[i].country, student_arr[i].city);
    }
}

// A utility function to swap two elements
/**
 * This function swaps 2 Student objects
 * @param student_a- the first student to swap
 * @param student_b- the second student to swap
 */
void swap(Student *student_a, Student *student_b)
{
    Student temp = *student_a;
    *student_a = *student_b;
    *student_b = temp;
}


/**
 * This function takes last element as pivot, places the pivot element at its correct position in
 * sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater
 * elements to right of pivot
 * @param student_arr- the array to sort
 * @param low- Starting index
 * @param high- Ending index
 * @return the new index location of the pivot value
 */
int partition(Student student_arr[], int low, int high)
{
    char pivot[FIELD_LENGTH];
    strcpy(pivot, student_arr[high].name);
    int i = (low - 1);
    for (
            int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (strcmp(student_arr[j].name, pivot) < 0)
        {
            i++;
            swap(&student_arr[i], &student_arr[j]);
        }
    }
    swap(&student_arr[i + 1], &student_arr[high]);
    return (i + 1);
}


/**
 * This function is the main function that implements QuickSort
 * @param student_arr- the array to sort
 * @param low- Starting index
 * @param high- Ending index
 */
void quickSort(Student student_arr[], int low, int high)
{
    if (low < high)
    {
        // p_i is partitioning index, arr[p] is now at right place
        int p_i = partition(student_arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(student_arr, low, p_i - 1);
        quickSort(student_arr, p_i + 1, high);
    }
}

/**
 * This function operates the task of sorting the students array by names using quick sort
 */
void sortByName()
{
    Student student_arr[MAX_STUDENT];
    int count_row;
    int amount_student;
    parser(&count_row, &amount_student, student_arr);
    if (amount_student > 1)
    {
        quickSort(student_arr, 0, amount_student - 1);
    }
    for (
            int i = 0; i < amount_student; i++)
    {
        printf(MERGE_QUICK_OUT, student_arr[i].id, student_arr[i].name, student_arr[i].grade,
               (int) student_arr[i].age,
               student_arr[i].country, student_arr[i].city);
    }
}

/**
 * The main function of the program
 * @return
 */
int main(int argc, char *argv[])
{
    if (argc > 2 ||
        (strcmp(argv[1], BEST) != 0 && strcmp(argv[1], QUICK) != 0 && strcmp(argv[1], MERGE) != 0))
    {
        printf(ARGUMENT_MSG);
        return FAIL;
    }
    if (strcmp(argv[1], BEST) == 0)
    {
        best();
        return SUCCESS_MAIN;
    }
    if (strcmp(argv[1], MERGE) == 0)
    {
        sortByGrade();
        return SUCCESS_MAIN;
    }
    if (strcmp(argv[1], QUICK) == 0)
    {
        sortByName();
        return SUCCESS_MAIN;
    }
}


