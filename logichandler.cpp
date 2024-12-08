#include "logichandler.h"
#include <QDebug>
#include <QFile>

LogicHandler::LogicHandler()
{

}

void LogicHandler::BuildScene(QGraphicsScene* scene, int width, int height){
    this->rows = width;
    this->cols = height;
    this->scene = scene;
    for (int row = 0; row < width; ++row) {
        QVector<Tile*> tempVector;
        QVector<int> tempVector2;
        for (int col = 0; col < height; ++col) {
            Tile *tile = new Tile(QPixmap(":/Sprites/tilebase.png"), row, col);
            tile->setParent(this);
            tile->setPos(col * 50, row * 50);
            this->scene->addItem(tile);
            tempVector.push_back(tile);
            tempVector2.push_back(0);
        }
        tiles.push_back(tempVector);
        map.push_back(tempVector2);
    }

    this->landminesCount = width*height/8;
    qDebug() << QString::number(landminesCount);
    GenerateMap(this->landminesCount, width, height);
    UpdateTiles(width, height);
}

void LogicHandler::GenerateMap(int n, int rows, int cols){
    std::srand(std::time(0));
       int totalCells = rows * cols;

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

void LogicHandler::RevealCloseTiles(int row, int col)
{
    for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (dr == 0 && dc == 0) continue;

                int newRow = row + dr;
                int newCol = col + dc;

                if (newRow >= 0 && newRow < tiles.size() &&
                    newCol >= 0 && newCol < tiles[newRow].size()) {

                    Tile *neighbor = tiles[newRow][newCol];

                    if (!neighbor->isOpened && !neighbor->isFlagged) {
                        neighbor->RevealTile();
                        neighbor->isOpened = true;

                        if (neighbor->isEmpty) {
                            RevealCloseTiles(newRow, newCol);
                        }
                    }
                }
            }
        }
}
void LogicHandler::GameLost(){
     QMessageBox::information(nullptr, "Negative victory", "Congratulations! You blow up!");
     isGameActive = false;
     for (int i = 0; i < rows; ++i) {
         for (int j = 0; j < cols; ++j) {
             if(tiles[i][j]->isLandmine){
                tiles[i][j]->RevealTile();
             }
         }
     }
}

void LogicHandler::GameWon(){
    QMessageBox::information(nullptr, "Victory", "Congratulations! You won!");
    isGameActive = false;
}

void LogicHandler::FlagHandlerLogic(int type, int row, int col){
    if(type == 0){ totalFlags++; }
    else if(type == 1){ totalFlags++; correctFlags++; }
    else if(type == 2){ totalFlags--; }
    else if (type == 3) { totalFlags--; correctFlags--; }
    if(totalFlags > landminesCount){
        tiles[row][col]->RemoveFlagImage();
        totalFlags--;
    }
    if(correctFlags == landminesCount){ GameWon(); }
    qDebug() <<"Всего флагов " + QString::number(totalFlags);
    qDebug() <<"Всего правильных флагов " +QString::number(correctFlags);
}

void LogicHandler::UpdateTiles(int width, int height){
    for (int row = 0; row < width; ++row) {
        for (int col = 0; col < height; ++col) {
            switch (map[row][col]) {
            case 0:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tileused.png"), false, true);
                connect(tiles[row][col], &Tile::emptyTileRevealed, this, &LogicHandler::RevealCloseTiles);
                connect(tiles[row][col], &Tile::flagPlaced, this, &LogicHandler::FlagHandlerLogic);
                break;
            case 1:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tileone.png"), false, false);
                connect(tiles[row][col], &Tile::flagPlaced, this, &LogicHandler::FlagHandlerLogic);
                break;
            case 2:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tiletwo.png"), false, false);
                connect(tiles[row][col], &Tile::flagPlaced, this, &LogicHandler::FlagHandlerLogic);
                break;
            case 3:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tilethree.png"), false, false);
                connect(tiles[row][col], &Tile::flagPlaced, this, &LogicHandler::FlagHandlerLogic);
                break;
            case 4:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tilefour.png"), false, false);
                connect(tiles[row][col], &Tile::flagPlaced, this, &LogicHandler::FlagHandlerLogic);
                break;
            case 5:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tilefive.png"), false, false);
                connect(tiles[row][col], &Tile::flagPlaced, this, &LogicHandler::FlagHandlerLogic);
                break;
            case 6:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tilesix.png"), false, false);
                connect(tiles[row][col], &Tile::flagPlaced, this, &LogicHandler::FlagHandlerLogic);
                break;
            case 7:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tileseven.png"), false, false);
                connect(tiles[row][col], &Tile::flagPlaced, this, &LogicHandler::FlagHandlerLogic);
                break;
            case 8:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/tileeight.png"), false, false);
                connect(tiles[row][col], &Tile::flagPlaced, this, &LogicHandler::FlagHandlerLogic);
                break;
            case 10:
                tiles[row][col]->SetImage(QPixmap(":/Sprites/landmine.png"), true, false);
                connect(tiles[row][col], &Tile::mineClicked, this, &LogicHandler::GameLost);
                connect(tiles[row][col], &Tile::flagPlaced, this, &LogicHandler::FlagHandlerLogic);
                break;
            }
        }
    }
}

