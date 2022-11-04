
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<time.h>

void setValues(char filePath[]) {
    FILE* file;
    double x[3];

    for (int i = 0; i < 3; i++) {
        printf("Please, enter %d value: ", i);
        scanf("%lf", x + i);
    }

    file = fopen(filePath, "wb");
    if (file != NULL) {
        fwrite(x, sizeof(double), 3, file);
        fclose(file);
    }
}

void AddToLog(char message[]) {
    FILE* logStream;
    char logPath[] = "Log.txt",  logStr[100];

    logStream = fopen(logPath, "a");
    if (logStream != NULL) {
        time_t currentTime;
        time(&currentTime);
        
        strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

        strcat(logStr, "]: ");
        strcat(logStr, message);
        fprintf(logStream, "[%s\n", logStr);
        fclose(logStream);
    }
}

void Formula(double x, double y, double z, double* result, int* isPossible) {
    do {
        if ((x - y <= 0 && z - (int)z == 0) || pow((x - y), z) + pow(x, 2) == 0) {
            //printf("\nSorry, but we can't perform this operation, because values of variables you chose lie beyond the domain of a function\n");
            AddToLog("Error in calculating");
            break;
        }

        *result = (x + 3 * (x - y) + pow(x, 2)) / (pow((x - y), z) + pow(x, 2));
        *isPossible = 1;
        AddToLog("result was calculated successfully");
        //printf("\nResult is %lf\n", b);

    } while (0);
}

int main(void) {
    FILE* file;
    char readFrom[1000], writeInto[1000];
    double xyz[3] = { 0 }, result = 0;
    int isPossible = 0;

    AddToLog("Program has started");

    printf("Path of the file with start values: ");
    scanf("%s", readFrom);
    //setValues(readFrom);

    file = fopen(readFrom, "rb");
    if (file != NULL) {
        fread(xyz, sizeof(double), 3, file);
        fclose(file);

        AddToLog("Values was read");
    }
    char modeExtention[100], resStr[100];

    Formula(xyz[0], xyz[1], xyz[2], &result, &isPossible);

    printf("Path of the target file: ");
    scanf("%s", writeInto);

    while (isPossible) {
        printf("Text or binary representation ('t' or 'b'): ");
        scanf("%s", modeExtention);

        if (!strcmp(modeExtention, "b")) {

            file = fopen(writeInto, "wb");

            if (file != NULL) {
                fwrite(&result, sizeof(double), 1, file);
                fclose(file);
                AddToLog("Result was added as binary");
            }
            break;
        }
        else if (!strcmp(modeExtention, "t")) {

            file = fopen(writeInto, "wt");

            if (file != NULL) {
                fprintf(file, "%lf", result);
                fclose(file);

                AddToLog("Result was added as text");
                break;
            }
            else {
                AddToLog("Uncorrect input value for binary or text mode");
            }
        }
    }

    AddToLog("End of the program");
    return 0;
}