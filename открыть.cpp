#include <iostream>
#include <dirent.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{

    // Открываем папку с изображениями
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir("PATH")) != NULL)
    {
        // Цикл по всем файлам в папке
        while ((ent = readdir(dir)) != NULL)
        {
            // Исключаем папки . и ..
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            {
                continue;
            }
                // Получаем полный путь файла
            string path = "PATH";
            path += "/";
            path += ent->d_name;

                // Открываем изображение
            Mat image = imread(path, IMREAD_UNCHANGED);
            if (image.empty())
                {
                    cerr << "Error: Could not read file " << path << endl;
                    continue;
                }
                imshow("Image", image);
                waitKey(0);
            }
            closedir(dir);
        }
        else
        {
            cerr << "Error: Could not open directory "  << endl;
            return 1;
        }

        return 0;
    }
