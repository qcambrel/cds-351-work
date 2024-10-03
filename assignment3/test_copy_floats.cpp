# include <iostream>
// Place the code for the copy_floats function here .

void copy_floats(float * src, int ncopy, float * dest)
{
    for (int i = 0; i < ncopy; i++){
        dest[i] = src[i];
    }
}

int main ()
{
    // declare a source array with 6 elements
    float src[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

    // declare a destination array with 6 elements
    float dest[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    // call copy_floats
    int n = sizeof(src) / sizeof(float);
    copy_floats(src, n, dest);

    // Verify that your copy worked ( hint : use a for loop )
    for (int i = 0; i < n; i++){
        if (dest[i] != src[i]){
            std::cout << "copy_floats failed" << std::endl;
            return 1;
        }
    }
    std::cout << "copy_floats passed" << std::endl;
    return 0;
}