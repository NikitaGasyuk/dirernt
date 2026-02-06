#include <iostream>
// подключаемый файл для работы с директорией
#include <dirent.h>
// подключаемый файл для работы с opencv
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{

    // Открываем папку с изображениями
    // переменная в которую будет записана открытая директория(путь к файлу) 
    DIR* dir;
    // структура содержащая информацию об элементе директории
    struct dirent* ent;
    // проверка на то что путь к открываемой директории существует или правильно указан
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

            // инициализируем массив mat который хранит изображения
            // получаемые изображения записываются в него
            Mat image = imread(path, IMREAD_UNCHANGED);
            // проверяем получилось ли открыть у нас изображение
            if (image.empty())
            {
                 cerr << "Error: Could not read file " << path << endl;
                continue;
            }
            // выводим изображение на экран
            imshow("Image", image);
            // устанавливаем время нажатия пользователем клавищ, в данном случае время ожидания не ограничено
            waitKey(0);
        }
            // закрываем папку к оторой обращались для просмотра изображений
            closedir(dir);
    }
     else
    {
        // вывод ошибки если с директорией что-то не так
        cerr << "Error: Could not open directory "  << endl;
         return 1;
    }
    
        return 0;
    }
