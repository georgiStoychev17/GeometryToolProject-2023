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
* file with all line equations needed
*
*/

#include <iostream>
#include "Utilities.h"

void PrintLineEquation(double lineOne[3]) {
    if (lineOne[0] == 0 && lineOne[2] != 0) {
        std::cout << lineOne[1] << "y + " << lineOne[2] << " = 0";
    }
    else if (lineOne[0] != 0 && lineOne[2] == 0) {
        std::cout << lineOne[0] << "x + " << lineOne[2] << " = 0";
    }
    else if (lineOne[0] == 0 && lineOne[2] == 0) {
        std::cout << "That is not a valid line.";
    }
    else if (lineOne[1] < MIN && lineOne[2] < MIN) {
        std::cout << lineOne[0] << "x " << lineOne[1] << "y " << lineOne[2] << " = 0";
    }
    else if (lineOne[2] < MIN) {
        std::cout << lineOne[0] << "x + " << lineOne[1] << "y " << lineOne[2] << " = 0";
    }
    else if (lineOne[1] < MIN) {
        std::cout << lineOne[0] << "x " << lineOne[1] << "y + " << lineOne[2] << " = 0";
    }
    else {
        std::cout << lineOne[0] << "x + " << lineOne[1] << "y + " << lineOne[2] << " = 0";
    }
}

bool IsAPointOnALine(double FirstPointCoord[2], double lineOne[3]) {
    return CustomFabs(FirstPointCoord[1] + ((lineOne[0] / lineOne[1]) * FirstPointCoord[0] + (lineOne[2] / lineOne[1])) < MIN);
}

void FindAngleCoefficientEquation(double xCoordinate, double yCoordinate, double AngleCoefficient) {

    if (AngleCoefficient != 0 && ((yCoordinate - (AngleCoefficient * xCoordinate)) > MIN)) {
        std::cout << "y = " << AngleCoefficient << "x + " << (yCoordinate - (AngleCoefficient * xCoordinate));
    }
    else if (AngleCoefficient != 0 && ((yCoordinate - (AngleCoefficient * xCoordinate)) < MIN)) {
        std::cout << "y = " << AngleCoefficient << "x " << (yCoordinate - (AngleCoefficient * xCoordinate));
    }
    else if (AngleCoefficient == 0) {
        std::cout << "y = " << yCoordinate;
    }
    else {
        std::cout << "y = " << AngleCoefficient << "x";
    }
}

void FindParalelLineEquation(double FirstPointCoord[2], double lineOne[3]) {
    double SecondAngleCoef = -(lineOne[0] / lineOne[1]); // parallel lines (first angle coef = second angle coef)
    if (lineOne[1] == 0) {
        SecondAngleCoef = 0;
    }
    FindAngleCoefficientEquation(FirstPointCoord[0], FirstPointCoord[1], SecondAngleCoef);
}

void FindPerpendicularLineEquation(double FirstPointCoord[2], double lineOne[3]) {
    double AngleCoefficient2 = (lineOne[1] / lineOne[0]); //k2 =-1 / k1 = -1 / -(A / B) = B / A
    FindAngleCoefficientEquation(FirstPointCoord[0], FirstPointCoord[1], AngleCoefficient2);
}

bool TwoLinesAreParallel(double lineOne[3], double lineTwo[3]) {
    if (lineOne[0] == 0 && lineTwo[0] == 0) {
        return lineOne[1] == lineTwo[1];
    }
    else if (lineOne[1] == 0 && lineTwo[1] == 0) {
        return lineOne[0] == lineTwo[0];
    }
    return (lineOne[0] / lineTwo[0]) == (lineOne[1] / lineTwo[1]);
}

bool TwoLinesAreMatching(double lineOne[3], double lineTwo[3]) {
    return TwoLinesAreParallel(lineOne, lineTwo) && (lineOne[2] == lineTwo[2]);
}

bool HasIntersectionPoint(double lineOne[3], double lineTwo[3]) {
    double AngleCoefficient1 = -(lineOne[0] / lineOne[1]);
    double AngleCoefficient2 = -(lineTwo[0] / lineTwo[1]);

    //if the two lines are parallel => they do not have an intersection point
    return (AngleCoefficient1 != AngleCoefficient2);
}

void FindIntersectionPoint(double lineOne[3], double lineTwo[3], double IntersecPoint[2]) {
    double determinantX = -(lineOne[2] * lineTwo[1]) + (lineOne[1] * lineTwo[2]);
    double determinantY = -(lineOne[0] * lineTwo[2]) + (lineOne[2] * lineTwo[0]);
    double determinantBase = -(lineOne[0] * lineTwo[1]) + (lineTwo[0] * lineOne[1]);

    //double IntersecPoint[2];
    IntersecPoint[0] = -determinantX / determinantBase;
    IntersecPoint[1] = -determinantY / determinantBase;
}

void PrintIntersecPoint(double* IntersecPoint) {
    std::cout << "(" << IntersecPoint[0] << ", " << IntersecPoint[1] << ")" << std::endl << std::endl;
}

void PrintCartesianLineEquation(double FirstLineFirstCoef, double FirstLineSecondCoef, double FirstLineThirdCoef) {
    if (-(FirstLineFirstCoef / FirstLineSecondCoef) == 0) {
        std::cout << "y = " << -(FirstLineThirdCoef / FirstLineSecondCoef);
    }
    else if (FirstLineSecondCoef == 0) {
        std::cout << "x = " << -(FirstLineThirdCoef / FirstLineFirstCoef);
    }
    else if (-(FirstLineThirdCoef / FirstLineSecondCoef) < MIN) {
        std::cout << "y = " << -(FirstLineFirstCoef / FirstLineSecondCoef) << "x " << -(FirstLineThirdCoef / FirstLineSecondCoef);
    }
    else {
        std::cout << "y = " << -(FirstLineFirstCoef / FirstLineSecondCoef) << "x + " << -(FirstLineThirdCoef / FirstLineSecondCoef);
    }
}

void PrintLineEquationWithTwoPoints(double FirstXCoord, double FirstYCoord, double SecondXCoord, double SecondYCoord) {
    double A = SecondYCoord - FirstYCoord;
    double B = FirstXCoord - SecondXCoord;
    double C = FirstYCoord * SecondXCoord - FirstXCoord * SecondYCoord;

    PrintCartesianLineEquation(A, B, C);
}
