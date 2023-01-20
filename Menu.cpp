/**
*
* Solution to course project # 03
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Georgi Stoychev
* @idnumber 7MI0600157
* @compiler VC
*
* file, printing the menu
*
*/

#include <iostream>
#include <iomanip>
#include "Utilities.h"
#include "Lines.h"
#include "Parabola.h"
#include "Triangle.h"
#include "Quadrilateral.h"


void DefineALine(char* symbolName, double lineOne[3]) {
    std::cout << "Enter the coefficients (A,B,C) of the line (Ax + By + C = 0) you want to define: ";
    std::cin >> lineOne[0] >> lineOne[1] >> lineOne[2];

    std::cout << "Name the line: ";
    GetSymbol(symbolName);

    std::cout << "The equation of the line is: " << symbolName << ": ";
    PrintLineEquation(lineOne);
    std::cout << std::endl << std::endl;
}

void LiesOnLine(char* symbolName, double FirstPointCoord[2], double lineOne[3]) {

    std::cout << "Name the point: ";
    GetSymbol(symbolName);

    std::cout << "Enter " << symbolName << "'s coordinates: ";
    std::cin >> FirstPointCoord[0] >> FirstPointCoord[1];

    std::cout << "Enter the coefficients (A,B,C) of the line (Ax + By + C = 0) you want to define: ";
    std::cin >> lineOne[0] >> lineOne[1] >> lineOne[2];

    if (IsAPointOnALine(FirstPointCoord, lineOne)) {
        std::cout << symbolName << " lies on the line. " << std::endl << std::endl;
    }
    else {
        std::cout << symbolName << " does not lie on the line" << std::endl << std::endl;
    }
}

void ParalelEquation(char* symbolName, double FirstPointCoord[2], double lineOne[3]) {

    std::cout << "Enter the coefficients (A,B,C) of the line (Ax + By + C = 0) you want to define: ";
    std::cin >> lineOne[0] >> lineOne[1] >> lineOne[2];

    std::cout << "Enter the point's coordinates: ";
    std::cin >> FirstPointCoord[0] >> FirstPointCoord[1];

    std::cout << "Name the formed equation: ";
    GetSymbol(symbolName);

    std::cout << "The equation of the parallel line between the point and the given line is: " << symbolName << ": ";
    FindParalelLineEquation(FirstPointCoord, lineOne);
    std::cout << std::endl << std::endl;
}

void PerpendicullarEquation(char* symbolName, double FirstPointCoord[2], double lineOne[3]) {
    std::cout << "Enter the coefficients (A,B,C) of the line (Ax + By + C = 0) you want to define: ";
    std::cin >> lineOne[0] >> lineOne[1] >> lineOne[2];

    std::cout << "Enter the point's coordinates: ";
    std::cin >> FirstPointCoord[0] >> FirstPointCoord[1];

    if (!IsAPointOnALine(FirstPointCoord, lineOne)) {
        std::cout << "The point must lie on the given line!";
        return;
    }

    std::cout << "Name the formed equation: ";
    GetSymbol(symbolName);

    std::cout << "The equation of the perpendicular line between the point and the given line is: " << symbolName << ": ";
    FindPerpendicularLineEquation(FirstPointCoord, lineOne);
    std::cout << std::endl << std::endl;

}

void IntersecPointTwoLines(char* symbolName, double lineOne[3], double lineTwo[3]) {
    std::cout << "Enter the coefficients (A,B,C) of the first line (Ax + By + C = 0) you want to define: ";
    std::cin >> lineOne[0] >> lineOne[1] >> lineOne[2];

    std::cout << "Enter the coefficients (D,E,F) of the second line (Dx + Ey + F = 0) you want to define: ";
    std::cin >> lineTwo[0] >> lineTwo[1] >> lineTwo[2];

    std::cout << "Name the intersection point: ";
    GetSymbol(symbolName);

    if (TwoLinesAreMatching(lineOne, lineTwo)) {
        std::cout << "There are infinite intersection points.";
        return;
    }

    if (!HasIntersectionPoint(lineOne, lineTwo)) {
        std::cout << "There cannot be an intersection point between these two lines!";
        return;
    }
    else {
        double IntersecPoint[2];
        FindIntersectionPoint(lineOne, lineTwo, IntersecPoint);
        std::cout << "The point's coordinates are: " << symbolName << " ";
        PrintIntersecPoint(IntersecPoint);
    }
}

void TangentParabolaPoint(char* symbolName, double ParabolaCoef[3], double FirstPointCoord[2]) {
    std::cout << "Enter the coefficients (A,B,C) of the parabola (Ax^2 + Bx + C = y) you want to define: ";
    std::cin >> ParabolaCoef[0] >> ParabolaCoef[1] >> ParabolaCoef[2];

    std::cout << "Name a point: ";
    GetSymbol(symbolName);

    std::cout << "Enter " << symbolName << "'s coordinates: ";
    std::cin >> FirstPointCoord[0] >> FirstPointCoord[1];
    std::cout << std::endl;

    FindTangentToParabolaEquation(ParabolaCoef, FirstPointCoord);
    std::cout << std::endl << std::endl;

}

void TangentLineParabola(double ParabolaCoef[3], double lineOne[3]) {
    std::cout << "Enter the coefficients (A,B,C) of the parabola (Ax^2 + Bx + C = y) you want to define: ";
    std::cin >> ParabolaCoef[0] >> ParabolaCoef[1] >> ParabolaCoef[2];

    std::cout << "Enter the coefficients (D,E,F) of the line (Dx + Ey + F = 0) you want to define: ";
    std::cin >> lineOne[0] >> lineOne[1] >> lineOne[2];

    FindInterPointBetwParAndLine(lineOne, ParabolaCoef);
}

void TriangleEquations(char* symbolName, double FirstPointCoord[2], double SecondPointCoord[2], double ThirdPointCoord[2]) {
    std::cout << "In order to find such equations, a triangle must be formed first." << std::endl << std::endl;

    std::cout << "Name the first point: ";
    GetSymbol(symbolName);

    std::cout << "Enter " << symbolName << "'s coordinates: ";
    std::cin >> FirstPointCoord[0] >> FirstPointCoord[1];

    std::cout << "Name the second point: ";
    GetSymbol(symbolName);

    std::cout << "Enter " << symbolName << "'s coordinates: ";
    std::cin >> SecondPointCoord[0] >> SecondPointCoord[1];

    std::cout << "Name the third point: ";
    GetSymbol(symbolName);                                                    

    std::cout << "Enter " << symbolName << "'s coordinates: ";
    std::cin >> ThirdPointCoord[0] >> ThirdPointCoord[1];
    std::cout << std::endl;

    if (!IsATriangle(FirstPointCoord, SecondPointCoord, ThirdPointCoord)) {
        std::cout << "These points do not form a valid triangle." << std::endl << std::endl;
    }
    else {
        HeightEquations(FirstPointCoord[0], FirstPointCoord[1], SecondPointCoord[0], SecondPointCoord[1], ThirdPointCoord[0], ThirdPointCoord[1]);
        MedianEquations(FirstPointCoord[0], FirstPointCoord[1], SecondPointCoord[0], SecondPointCoord[1], ThirdPointCoord[0], ThirdPointCoord[1]);
        SimetralEquations(FirstPointCoord[0], FirstPointCoord[1], SecondPointCoord[0], SecondPointCoord[1], ThirdPointCoord[0], ThirdPointCoord[1]);
    }
}

void Quadrilateral(double QuadrilateralEquations[4][3], double lineOne[3], double lineTwo[3], double lineThree[3], double lineFour[3]) {

    std::cout << "Enter the coefficients (A,B,C) of the first line (Ax + By + C = 0) you want to define: ";
    std::cin >> lineOne[0] >> lineOne[1] >> lineOne[2];

    QuadrilateralEquations[0][0] = lineOne[0];
    QuadrilateralEquations[0][1] = lineOne[1];
    QuadrilateralEquations[0][2] = lineOne[2];

    std::cout << "Enter the coefficients (D,E,F) of the second line (Dx + Ey + F = 0) you want to define: ";
    std::cin >> lineTwo[0] >> lineTwo[1] >> lineTwo[2];

    QuadrilateralEquations[1][0] = lineTwo[0];
    QuadrilateralEquations[1][1] = lineTwo[1];
    QuadrilateralEquations[1][2] = lineTwo[2];

    std::cout << "Enter the coefficients (G,H,I) of the third line (Gx + Hy + I = 0) you want to define: ";
    std::cin >> lineThree[0] >> lineThree[1] >> lineThree[2];

    QuadrilateralEquations[2][0] = lineThree[0];
    QuadrilateralEquations[2][1] = lineThree[1];
    QuadrilateralEquations[2][2] = lineThree[2];

    std::cout << "Enter the coefficients (J,K,L) of the fourth line (Jx + Ky + L = 0) you want to define: ";
    std::cin >> lineFour[0] >> lineFour[1] >> lineFour[2];
    std::cout << std::endl;

    QuadrilateralEquations[3][0] = lineFour[0];
    QuadrilateralEquations[3][1] = lineFour[1];
    QuadrilateralEquations[3][2] = lineFour[2];

    if (!CanAQuadrilateralBeFormed(QuadrilateralEquations)) {
        std::cout << "Those lines can't form a quadrilateral";
        std::cout << std::endl;
        return;
    }
    QuadrilateralTypes(QuadrilateralEquations);
}

void MainMenu() {
    std::cout << std::setprecision(3);

    double A; double B; double C; double x; double y;

    int choice = 0;
    char symbolName[MAX_SIZE];
    double FirstPointCoord[2];
    double SecondPointCoord[2];
    double ThirdPointCoord[2];
    double ParabolaCoef[3];
    double lineOne[3];
    double lineTwo[3];
    double lineThree[3];
    double lineFour[3];
    double QuadrilateralEquations[4][3];

    do {

        std::cout << "+----+----+----+----+----+----+----+-----<MENU>-----+----+----+----+----+----+----+----+" << std::endl << std::endl;
        std::cout << " Actions:\n";
        std::cout << " 1) Define a line using its coefficients.\n";
        std::cout << " 2) Check if a point lies on a line.\n";
        std::cout << " 3) Find the equation of a parallel line (given a line and a point).\n";
        std::cout << " 4) Find the equation of line, perpendicular to a given point (given a line and a point).\n";
        std::cout << " 5) Find the intersection point between 2 lines (by given equations).\n";
        std::cout << " 6) Find the equation of the tangent, given an equation of a parabola and a point.\n";
        std::cout << " 7) Find the intersection point of a line and a parabola (with given equations).\n";
        std::cout << " 8) Find the equations of the heights/medians/meters (if a triangle exists).\n";
        std::cout << " 9) Determine the type of the quadrilateral, formed by the intersection of 4 line equations.\n";
        std::cout << " 10) Quit. \n\n";
        std::cout << "+----+----+----+----+----+----+----+----+---<===>---+----+----+----+----+----+----+----+ \n\n";
        std::cout << "Enter a choice: ";

        std::cin >> choice;

        clearConsole();

        switch (choice)
        {
        case 1:
            DefineALine(symbolName, lineOne);
            break;
        case 2:
            LiesOnLine(symbolName, FirstPointCoord, lineOne);
            break;
        case 3:
            ParalelEquation(symbolName, FirstPointCoord, lineOne);
            break;
        case 4:
            PerpendicullarEquation(symbolName, FirstPointCoord, lineOne);
            break;
        case 5:
            IntersecPointTwoLines(symbolName, lineOne, lineTwo);
            break;
        case 6:
            TangentParabolaPoint(symbolName, ParabolaCoef, FirstPointCoord);
            break;
        case 7:
            TangentLineParabola(ParabolaCoef, lineOne);
            break;
        case 8:
            TriangleEquations(symbolName, FirstPointCoord, SecondPointCoord, ThirdPointCoord);
            break;
        case 9:
            Quadrilateral(QuadrilateralEquations, lineOne, lineTwo, lineThree, lineFour);
            break;
        case 10:
            std::cout << "Thanks for using the program! Cya";
            break;

        default:
            std::cout << "Invalid menu choice. Try again! " << std::endl << std::endl;
            break;
        }
    } while (choice != 10);
}
