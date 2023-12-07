#include"Matrix.h"
#include<cmath>


const double pi = 3.14159265358979323846;
bool IsKeyPressed(int key) {
	return GetAsyncKeyState(key) & 0x8000;
}
void WaitForKey() {
	while (!IsKeyPressed(VK_SPACE) && !IsKeyPressed(VK_LEFT) && !IsKeyPressed(VK_RIGHT) && !IsKeyPressed(VK_DOWN)) {
		Sleep(50);
	}
}
Shape Matrix::InitShape() {
	srand(time(0));
	int randValue = rand() % 5;

	switch (randValue) {
	case 0:
		return I();
	case 1:
		return L();
	case 2:
		return Dot();
	case 3:
		return Z();
	case 4:
		return T();
	default:
		// Можливо, поверніть якусь фігуру за замовчуванням або обробіть інакше
		return Dot();
	}
}
void Matrix::Gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Matrix::ClearBoard() {
    for (int i = 0; i < 20; i++) {
        Gotoxy(11, i);
       
        cout << char(186);
    }
    for (int i = 0; i < 11; i++) {
        Gotoxy(i, 20);
        cout << char(205);
    }
    Gotoxy(11, 20);
    cout << char(188);
    
}
void Matrix::ClearRow(int rowIndex) {
    vector<Point> aboveRow;
    // Переміщення всіх рядків вище вниз на один рядок
    for (int x = 0; x < 10; ++x) {
        Gotoxy(x, rowIndex);
        cout << ' ';

        // Збереження фігур, що перебувають над видаленим рядком
        for (const auto& point : points) {
            if (point.y < rowIndex) {
                aboveRow.push_back(point);
            }
        }
    }

    // Видалення точок у повному рядку
    points.erase(
        remove_if(points.begin(), points.end(),
            [rowIndex](const Point& point) { return point.y == rowIndex; }),
        points.end());

    // Зсув точок вище вниз
    for (auto& point : points) {
        if (point.y < rowIndex) {
            point.y++;
        }
    }

    // Перемалювання фігур, що перебувають над видаленим рядком
    for (const auto& point : aboveRow) {
        Gotoxy(point.x, point.y);
        cout << " ";
    }

    // Оновлення виводу на екрані
    ShowBoard();
    score += 10;
  
}

void Matrix::CheckRows() {
    vector<int> fullRows;

    // Знайдемо всі повні рядки
    for (int y = 0; y < 20; ++y) {
        bool rowIsFull = true;
        for (int x = 0; x < 10; ++x) {
            if (!IsOccupied(x, y)) {
                rowIsFull = false;
                break;
            }
        }

        if (rowIsFull) {
            fullRows.push_back(y);
        }
    }

    // Видалимо повні рядки та зсунемо решту вниз
    for (int rowIndex : fullRows) {
        ClearRow(rowIndex);
    }

    // Оновимо вивід на екрані
    ShowBoard();

}
void Matrix::ShowBoard() {
    ClearBoard();
    for (const auto& point : points) {
        Gotoxy(point.x, point.y);
        cout << char(219);
    }
}

void Matrix::DrawShape( Shape& shape) {
    for (const auto& point : shape.GetShape()) {
        Gotoxy(point.x, point.y);
        cout << char(219);
    }
}

//void Matrix::FallShape(Shape& shape) {
//    while (CanMoveDown(shape)) {
//        if (_kbhit()) {
//            char key = _getch();
//            switch (key) {
//            case VK_LEFT:
//                MoveShapeLeft(shape);
//                break;
//            case VK_RIGHT:
//                MoveShapeRight(shape);
//                break;
//            }
//        }
//
//        ClearShape(shape);
//        shape.ShapeMoveDown();
//        DrawShape(shape);
//        Sleep(500);
//    }
//
//    MergeShape(shape);
//    CheckRows();
//}

bool Matrix::CanMoveDown( Shape& shape)  {
    for (const auto& point : shape.GetShape()) {
        if (point.y >= 19 || IsOccupied(point.x, point.y + 1)) {
            return false;
        }
    }
    return true;
}

void Matrix::ClearShape( Shape& shape) {
    for (const auto& point : shape.GetShape()) {
        Gotoxy(point.x, point.y);
        cout << ' ';
        points.erase(remove(points.begin(), points.end(), point), points.end());
    }
}

void Matrix::MoveShapeRight(Shape& shape) {
    if (CanMoveRight(shape)) {
        ClearShape(shape);
        shape.MoveRight();
        DrawShape(shape);
    }
}

void Matrix::MoveShapeLeft(Shape& shape) {
    if (CanMoveLeft(shape)) {
        ClearShape(shape);
        shape.MoveLeft();
        DrawShape(shape);
    }
}

bool Matrix::CanMoveRight( Shape& shape)  {
    for (const auto& point : shape.GetShape()) {
        if (point.x >= 10 || IsOccupied(point.x + 1, point.y)) {
            return false;
        }
    }
    return true;
}

bool Matrix::CanMoveLeft( Shape& shape)  {
    for (const auto& point : shape.GetShape()) {
        if (point.x <= 0 || IsOccupied(point.x - 1, point.y)) {
            return false;
        }
    }
    return true;
}

void Matrix::MergeShape( Shape& shape) {
    for (const auto& point : shape.GetShape()) {
        points.push_back(point);
        shape.GetShape().clear();
    }
}

bool Matrix::IsOccupied(int x, int y)  {
    for (const auto& point : points) {
        if (point.x == x && point.y == y) {
            return true;
        }
    }
    return false;
}
 bool Matrix::IsCollision( Shape& shape)  {
     for (const auto& point : shape.GetShape()) {
         int x = point.x;
         int y = point.y;

         // Перевірка в межах існуючої матриці
         if (x < 0 || x >= 10 || y < 0 || y >= 20) {
             return true;
         }

         // Перевірка колізії з існуючими точками
         if (IsOccupied(x, y)) {
             return true;
         }
     }

     return false;
}
 bool Matrix::CheckOver() {
     for (const auto& point : points) {
         if (point.y == 0)return true;
     }
     return false;
 }
 void RotatePoint(Point& point, const Point& center, double angle) {
     int relativeX = point.x - center.x;
     int relativeY = point.y - center.y;

     double newX = center.x + (relativeX * cos(angle) - relativeY * sin(angle));
     double newY = center.y + (relativeX * sin(angle) + relativeY * cos(angle));

     point.x = static_cast<int>(round(newX));
     point.y = static_cast<int>(round(newY));
 }
 Point Matrix::GetRotationCenter( Shape& shape) {
     // Знаходження центральної точки для обертання
     int totalX = 0, totalY = 0;
     for (const auto& point : shape.GetShape()) {
         totalX += point.x;
         totalY += point.y;
     }

     int centerX = totalX / shape.GetShape().size();
     int centerY = totalY / shape.GetShape().size();

     return Point(centerX, centerY);
 }
void Matrix::RotateShape(Shape& shape) {
    // Копіювання оригінальної фігури для тестування обертання
    Shape rotatedShape = shape;

    // Знаходження центральної точки обертання
    Point rotationCenter = GetRotationCenter(rotatedShape);

    // Кут обертання (90 градусів проти годинникової стрілки)
    double angle = pi / 2.0;

    // Обертання кожної точки навколо центральної точки
    for (auto& point : rotatedShape.GetShape()) {
        RotatePoint(point, rotationCenter, angle);
    }

    // Перевірка колізії після обертання
    if (!IsCollision(rotatedShape)) {
        // Заміна оригінальної фігури оберненою
        shape = rotatedShape;
    }
}

void Matrix::Play() {
    bool end = false;
    ShowBoard();
  
    while (!end) {
        ClearBoard();
        Shape shape = InitShape();
        while (CanMoveDown(shape)) {
            if (_kbhit()) {
                char key = _getch();
                switch (key) {
                case 'a':
                    MoveShapeLeft(shape);
                    break;
                case 'd':
                    MoveShapeRight(shape);
                    break;
                case 's':
                    if (CanMoveDown(shape)) { 
                        ClearShape(shape);
                        shape.ShapeMoveDown();
                        DrawShape(shape);
                    }
                    break;
                case 'r':
                    RotateShape(shape);
                    break;
                }
            }

            ClearShape(shape);
            shape.ShapeMoveDown();
            DrawShape(shape);
           
            Sleep(200);
            
        }
        MergeShape(shape);
        CheckRows();
        Gotoxy(12, 1);
        cout << "SCORE: " << score;
        if (CheckOver()) {
            end = true;
            Gotoxy(20, 20);
            cout << "Game Over! Your Score:"<< score << endl;
            points.clear();
        }
    }
}



