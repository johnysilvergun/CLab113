// Read scores from the specified file
// Then report the average value.
// อ่านข้อมูลคะแนนจากไฟล์ จากนั้นคำนวณหาค่าเฉลี่ยของคะแนนในไฟล์ดังกล่าว
// ฟังก์ชัน findAverage ที่รับชื่อไฟล์ และคืนค่าเฉลี่ยของคะแนนในไฟล์
// Example 1

// Suppose the file scores.txt contains the following:

// 89
// 42
// 70
// 85
// 33
// 26
// 29
// 65
// 27
// 84

// Then the program's output should be:

// scores.txt
// Average score is 55.0000



// Example 2
// The file big-scores.txt contains 100 scores, which should produce the following output: 

// big-scores.txt
// Average score is 64.6700


#include <stdio.h>

double findAverage(char *filename)
{
    FILE *file;
    int number = 0;
    int c = 0;
    double sum = 0;
    file = fopen(filename, "r");
    if (file != NULL) {
        while (fscanf(file,"%d",&number) != EOF) {
            sum += number;
            c++;
        }
        fclose(file);
        return sum/c;
    }
    else
    
    {
        return 0;
    }

}

int main()
{
    char filename[20];
    double average;
    scanf("%s", filename);
    average = findAverage(filename);
    printf("Average score is %.4lf\n", average);
}