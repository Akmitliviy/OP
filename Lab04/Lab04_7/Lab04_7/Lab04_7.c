
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

int main(void) {
    FILE* file, * logStream;
    char readFrom[1000], writeInto[1000], logPath[] = "Log.txt", logStr[100];
    double xyz[3] = { 0 }, x, y, z, result = 0;
    time_t currentTime;



    logStream = fopen(logPath, "a");
    if (logStream != NULL) {
        time(&currentTime);

        strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

        strcat(logStr, "]: ");
        strcat(logStr, "Program has started");
        fprintf(logStream, "[%s\n", logStr);
        fclose(logStream);
    }

    printf("Path of the file with start values: ");
    scanf("%s", readFrom);
    //setValues(readFrom);

    file = fopen(readFrom, "rb");
    if (file != NULL) {
        fread(xyz, sizeof(double), 3, file);
        fclose(file);

        logStream = fopen(logPath, "a");
        if (logStream != NULL) {
            time(&currentTime);

            strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

            strcat(logStr, "]: ");
            strcat(logStr, "Values was read");
            fprintf(logStream, "[%s\n", logStr);
            fclose(logStream);
        }
    }

    x = xyz[0];
    y = xyz[1];
    z = xyz[2];

    printf("Path of the target file: ");
    scanf("%s", writeInto);
    do {
        if ((x - y <= 0 && z - (int)z == 0) || pow((x - y), z) + pow(x, 2) == 0) {
            //printf("\nSorry, but we can't perform this operation, because values of variables you chose lie beyond the domain of a function\n");


            logStream = fopen(logPath, "a");
            if (logStream != NULL) {
                time(&currentTime);

                strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

                strcat(logStr, "]: ");
                strcat(logStr, "Error in calculating");
                fprintf(logStream, "[%s\n", logStr);
                fclose(logStream);
                break;
            }
        }

        result = (x + 3 * (x - y) + pow(x, 2)) / (pow((x - y), z) + pow(x, 2));


        logStream = fopen(logPath, "a");
        if (logStream != NULL) {
            time(&currentTime);

            strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

            strcat(logStr, "]: ");
            strcat(logStr, "result was calculated successfully");
            fprintf(logStream, "[%s\n", logStr);
            fclose(logStream);
            //printf("\nResult is %lf\n", b);
        }

        char modeExtention[100], resStr[100];

        while (1) {
            printf("Text or binary representation ('t' or 'b'): ");
            scanf("%s", modeExtention);

            if (!strcmp(modeExtention, "b")) {

                file = fopen(writeInto, "wb");

                if (file != NULL) {
                    fwrite(&result, sizeof(double), 1, file);
                    fclose(file);

                    logStream = fopen(logPath, "a");
                    if (logStream != NULL) {
                        time(&currentTime);

                        strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

                        strcat(logStr, "]: ");
                        strcat(logStr, "Result was added as binary");
                        fprintf(logStream, "[%s\n", logStr);
                        fclose(logStream);
                    }
                }
                break;
            }
            else if (!strcmp(modeExtention, "t")) {

                file = fopen(writeInto, "wt");

                if (file != NULL) {
                    fprintf(file, "%lf", result);
                    fclose(file);

                    logStream = fopen(logPath, "a");
                    if (logStream != NULL) {
                        time(&currentTime);

                        strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

                        strcat(logStr, "]: ");
                        strcat(logStr, "Result was added as text");
                        fprintf(logStream, "[%s\n", logStr);
                        fclose(logStream);
                    }
                    break;
                }
                else {

                    logStream = fopen(logPath, "a");
                    if (logStream != NULL) {
                        time(&currentTime);

                        strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

                        strcat(logStr, "]: ");
                        strcat(logStr, "Uncorrect input value for binary or text mode");
                        fprintf(logStream, "[%s\n", logStr);
                        fclose(logStream);
                    }
                }
            }
        }
    } while (0);


    time(&currentTime);

    logStream = fopen(logPath, "a");
    if (logStream != NULL) {
        strftime(logStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&currentTime));

        strcat(logStr, "]: ");
        strcat(logStr, "End of the program");
        fprintf(logStream, "[%s\n", logStr);
        fclose(logStream);
        return 0;
    }
}