#include "logichandler.h"
#include "tile.h"
#include <QDebug>
#include <QFile>

LogicHandler::LogicHandler()
{

}

void LogicHandler::BuildScene(QGraphicsScene* scene, int width, int height){
    for (int row = 0; row < width; ++row) {
        for (int col = 0; col < height; ++col) {
            Tile *tile = new Tile(QPixmap(":/Sprites/tilebase.png"));
//            QGraphicsPixmapItem* item = new Tile(QPixmap(":/Sprites/tilebase.png"));
            tile->setPos(col * 50, row * 50);
            scene->addItem(tile);
            tiles.append(tile);

           // tile->SetImage();

           // tiles[0]->SetImage();
        }
    }
}

void LogicHandler::GenerateMap(int n, int rows, int cols){
    std::srand(std::time(0));

       // Размер массива
       int totalCells = rows * cols;

       // Проверка на допустимое число бомб
       if (n > totalCells) {
           //std::cerr << "Слишком много бомб для заданного размера массива!" << std::endl;
           return;
       }

       // Расставляем бомбы случайным образом
       std::vector<int> positions(totalCells, 0);
       for (int i = 0; i < n; ++i) {
           positions[i] = 10;
       }

       std::random_shuffle(positions.begin(), positions.end());

       // Переносим одномерный массив в двумерный
       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < cols; ++j) {
               this->map[i][j] = positions[i * cols + j];
           }
       }

       // Вычисляем количество соседей-бомб для каждой клетки
       std::vector<int> directions = {-1, 0, 1}; // Для обхода соседей по 8 направлениям
       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < cols; ++j) {
               if (this->map[i][j] == 10) continue; // Пропускаем бомбы
               int count = 0;
               for (int di : directions) {
                   for (int dj : directions) {
                       if (di == 0 && dj == 0) continue; // Пропускаем текущую клетку
                       int ni = i + di, nj = j + dj;
                       if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && this->map[ni][nj] == 10) {
                           ++count;
                       }
                   }
               }
               this->map[i][j] = count;
           }
       }
   }

