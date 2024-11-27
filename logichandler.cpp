#include "logichandler.h"
#include <QDebug>
#include <QFile>

LogicHandler::LogicHandler()
{

}

void LogicHandler::BuildScene(QGraphicsScene* scene, int width, int height){
    for (int row = 0; row < width; ++row) {
        QVector<Tile*> tempVector;
        QVector<int> tempVector2;
        for (int col = 0; col < height; ++col) {
            Tile *tile = new Tile(QPixmap(":/Sprites/tilebase.png"));
            tile->setPos(col * 50, row * 50);
            scene->addItem(tile);
            //tiles[row][col] = tile;
            tempVector.push_back(tile);
            tempVector2.push_back(0);
        }
        tiles.push_back(tempVector);
        map.push_back(tempVector2);
    }
    GenerateMap(width*height/8, width, height);
    UpdateTiles(width, height);
}

void LogicHandler::GenerateMap(int n, int rows, int cols){
    std::srand(std::time(0));
       int totalCells = rows * cols;
       if (n > totalCells) {
           //std::cerr << "Слишком много бомб для заданного размера массива!" << std::endl;
           return;
       }

       std::vector<int> positions(totalCells, 0);
       for (int i = 0; i < n; ++i) {
           positions[i] = 10;
       }

       std::random_shuffle(positions.begin(), positions.end());

       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < cols; ++j) {
               this->map[i][j] = positions[i * cols + j];
           }
       }

       std::vector<int> directions = {-1, 0, 1};
       for (int i = 0; i < rows; ++i) {
           for (int j = 0; j < cols; ++j) {
               if (this->map[i][j] == 10) continue;
               int count = 0;
               for (int di : directions) {
                   for (int dj : directions) {
                       if (di == 0 && dj == 0) continue;
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

void LogicHandler::UpdateTiles(int width, int height){
    for (int row = 0; row < width; ++row) {
        for (int col = 0; col < height; ++col) {
            switch (map[row][col]) {
            case 0:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tileused.png")); break;
            case 1:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tileone.png")); break;
            case 2:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tiletwo.png")); break;
            case 3:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tilethree.png")); break;
            case 4:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tilefour.png")); break;
            case 5:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tilefive.png")); break;
            case 6:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tilesix.png")); break;
            case 7:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tileseven.png")); break;
            case 8:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tileeight.png")); break;
            case 10:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/landmine.png")); break;
            }
        }
    }
}

