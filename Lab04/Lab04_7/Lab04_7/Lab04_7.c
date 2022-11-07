
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

void setValues(char filePath[]) {
    FILE* file;
    double xyz[3];

    for (int i = 0; i < 3; i++) {
        printf("Please, enter %d value: ", i);
        scanf("%lf", xyz + i);
    }

    file = fopen(filePath, "wb");
    if (file != NULL) {
        fwrite(xyz, sizeof(double), 3, file);
        fclose(file);
    }
}

int main(void) {
    FILE* file, * logStream;
    char readFrom[1000], writeInto[1000], logPath[] = "Log.txt", logStr[100], tempStr[100];
    double xyz[3] = { 0 }, x, y, z, result = 0;
    time_t currentTime;
    int onGoing = 0;


    do {
        onGoing = 0;
        logStream = fopen(logPath, "a");
        
        if (logStream != NULL) {
            time(&currentTime);
            strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

            strcat(logStr, "]: Program has started");
            fprintf(logStream, "[%s\n", logStr);
            fclose(logStream);

            onGoing = 0;
        }
        else {
            logStream = fopen(logPath, "w");
            fclose(logStream);

            onGoing = 1;
        }

    } while (onGoing);

    printf("Path of the file with start values: ");
    scanf("%s", readFrom);
    do {
        onGoing = 0;

        file = fopen(readFrom, "rb");
        if (file != NULL) {
            //setValues(readFrom);
            fread(xyz, sizeof(double), 3, file);
            fclose(file);

            logStream = fopen(logPath, "a");

            if (logStream != NULL) {
                time(&currentTime);
                strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

                sprintf(tempStr, "]: Values was read: X = %lf, Y = %lf, Z = %lf", xyz[0], xyz[1], xyz[2]);
                strcat(logStr, tempStr);
                fprintf(logStream, "[%s\n", logStr);
                fclose(logStream);
            }

            onGoing = 0;
        }
        else {
            logStream = fopen(logPath, "a");

            if (logStream != NULL) {
                time(&currentTime);
                strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

                strcat(logStr, "]: Incorrect input file path");
                fprintf(logStream, "[%s\n", logStr);
                fclose(logStream);
            }
            onGoing = 1;

            printf("\nSorry, but this file doesn`t exist. Please, try again:\n");
            scanf("%s", readFrom);
        }

    } while (onGoing);

    x = xyz[0];
    y = xyz[1];
    z = xyz[2];

    do {
        if ((x - y <= 0 && z - (int)z != 0) || pow((x - y), z) + pow(x, 2) == 0) {
            printf("\nSorry, but we can't perform this operation, because values of variables lie beyond the domain of a function\n");


            logStream = fopen(logPath, "a");
            if (logStream != NULL) {
                time(&currentTime);
                strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

                strcat(logStr, "]: Error in calculating");
                fprintf(logStream, "[%s\n", logStr);
                fclose(logStream);
            }
            
            break;
        }

        result = (x + 3 * (x - y) + pow(x, 2)) / (pow((x - y), z) + pow(x, 2));
        printf("\nResult is %lf\n", result);

        printf("\nPath of the target file: ");
        scanf("%s", writeInto);

        logStream = fopen(logPath, "a");
        if (logStream != NULL) {
            time(&currentTime);
            strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));


            sprintf(tempStr, "]: Result was calculated successfully. Result = %lf", result);
            strcat(logStr, tempStr);
            fprintf(logStream, "[%s\n", logStr);
            fclose(logStream);
        }

        char modeExtention[100], resStr[100];

        while (1) {
            printf("\nIn which format you want to save result? ('text' or 'binary'): ");
            scanf("%s", modeExtention);

            if (!(strcmp(modeExtention, "binary") && strcmp(modeExtention, "b"))) {

                file = fopen(writeInto, "wb");

                if (file != NULL) {
                    fwrite(&result, sizeof(double), 1, file);
                    fclose(file);

                    logStream = fopen(logPath, "a");
                    if (logStream != NULL) {
                        time(&currentTime);
                        strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

                        strcat(logStr, "]: Result was saved as binary");
                        fprintf(logStream, "[%s\n", logStr);
                        fclose(logStream);
                    }

                    puts("\nResult was saved as binary");
                }
                break;
            }
            else if (!(strcmp(modeExtention, "text") && strcmp(modeExtention, "t"))) {

                file = fopen(writeInto, "wt");

                if (file != NULL) {
                    fprintf(file, "%lf", result);
                    fclose(file);

                    logStream = fopen(logPath, "a");
                    if (logStream != NULL) {
                        time(&currentTime);
                        strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

                        strcat(logStr, "]: Result was saved as text");
                        fprintf(logStream, "[%s\n", logStr);
                        fclose(logStream);
                    }

                    puts("\nResult was saved as text");
                }
                break;
            }
            else {

                logStream = fopen(logPath, "a");
                if (logStream != NULL) {
                    time(&currentTime);
                    strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

                    strcat(logStr, "]: Incorrect input value for binary or text mode");
                    fprintf(logStream, "[%s\n", logStr);
                    fclose(logStream);
                }
            }
        }
    } while (0);

    logStream = fopen(logPath, "a");
    if (logStream != NULL) {
        time(&currentTime);
        strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

        strcat(logStr, "]: End of the program\n");
        fprintf(logStream, "[%s\n", logStr);
        fclose(logStream);
    }

    return 0;
}