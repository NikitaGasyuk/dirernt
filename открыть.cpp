#include <iostream>
#include <dirent.h>
#include <opencv2/opencv.hpp>

    using namespace std;
    using namespace cv;

    int main(int argc, char** argv)
    {

        // Открываем папку с изображениями
        DIR* dir;
        struct dirent* ent;
        if ((dir = opendir("C://Users//Nikita//Desktop//robs")) != NULL)
        {
            // Цикл по всем файлам в папке
            while ((ent = readdir(dir)) != NULL)
            {
                // Исключаем папки . и ..
                if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
                    continue;

                // Получаем полный путь файла
                string path = "C://Users//Nikita//Desktop//robs";
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
            cerr << "Error: Could not open directory " << argv[1] << endl;
            return 1;
        }

        return 0;
    }
