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
* file with all needed parabola functions
*
*/

#include <iostream>
#include "Utilities.h"

double NumberOfIntersectionPoints(double lineOne[3]) {
    double discriminant = lineOne[1] * lineOne[1] - 4 * lineOne[0] * lineOne[2];
    int numberOfPoints = 0;

    if (discriminant > 0)
        numberOfPoints = 2;
    if (discriminant == 0)
        numberOfPoints = 1;
    if (discriminant < 0)
        numberOfPoints = 0;
    return numberOfPoints;
}

void FindTangentToParabolaEquation(double ParabolaCoef[3], double FirstPointCoord[2]) {
    // Ax^2 + Bx + C = y -> parabola equation / kx + n = y -> tangent equation
    double SecondEqualisedCoef = (-2 * ParabolaCoef[1] - 4 * ParabolaCoef[0] * FirstPointCoord[0]);
    double ThirdEqualisedCoef = (ParabolaCoef[1] * ParabolaCoef[1] - 4 * ParabolaCoef[0] * ParabolaCoef[2] + 4 * ParabolaCoef[0] * FirstPointCoord[1]);
    double discriminant = SecondEqualisedCoef * SecondEqualisedCoef - 4 * ThirdEqualisedCoef;
    double k1 = 0;
    double k2 = 0;
    double n1 = 0;
    double n2 = 0;

    if ((NumberOfIntersectionPoints(ParabolaCoef) == 0)) {
        // y = k1x + n1  y = k2x + n2
        k1 = (-SecondEqualisedCoef + sqrt(discriminant)) / 2.0;
        k2 = (-SecondEqualisedCoef - sqrt(discriminant)) / 2.0;

        n1 = FirstPointCoord[1] - k1 * FirstPointCoord[0];
        n2 = FirstPointCoord[1] - k2 * FirstPointCoord[0];

        std::cout << "The first tangent equation is: " << "y = " << k1 << "x + " << n1 << std::endl;
        std::cout << "The second tangent equation is: " << "y = " << k2 << "x + " << n2 << std::endl;

    }
    else if ((NumberOfIntersectionPoints(ParabolaCoef) == 1)) {

        if (FirstPointCoord[0] == (-ParabolaCoef[1] / 2 * ParabolaCoef[0])) {
            std::cout << "The tangent equation is: y = 0" << std::endl;
        }
        else {
            k1 = (-SecondEqualisedCoef + sqrt(discriminant)) / 2.0;
            k2 = (-SecondEqualisedCoef - sqrt(discriminant)) / 2.0;

            n1 = FirstPointCoord[1] - k1 * FirstPointCoord[0];
            n2 = FirstPointCoord[1] - k2 * FirstPointCoord[0];

            std::cout << "The first tangent equation is: " << "y = " << k1 << "x + " << n1 << std::endl;
            std::cout << "The second tangent equation is: " << "y = 0" << std::endl;
        }
    }
    else if ((NumberOfIntersectionPoints(ParabolaCoef) == 2)) {
        k1 = (-ParabolaCoef[1] + sqrt(discriminant)) / (2.0 * ParabolaCoef[0]);
        k2 = (-ParabolaCoef[1] - sqrt(discriminant)) / (2.0 * ParabolaCoef[0]);

        if ((ParabolaCoef[0] * (ParabolaCoef[0] * FirstPointCoord[0] * FirstPointCoord[0] + ParabolaCoef[1] * FirstPointCoord[0] + ParabolaCoef[2])) < MIN) {
            std::cout << "There are no tangent equations through this point.";
        }
        else if (FirstPointCoord[0] == k1) {
            n1 = FirstPointCoord[1] - k1 * FirstPointCoord[0];
            std::cout << "The tangent equation is: " << "y = " << k1 << "x + " << n1 << std::endl;
        }
        else if (FirstPointCoord[0] == k2) {
            n2 = FirstPointCoord[1] - k2 * FirstPointCoord[0];
            std::cout << "The tangent equation is: " << "y = " << k2 << "x + " << n2 << std::endl;
        }
        else {
            k1 = (-SecondEqualisedCoef + sqrt(discriminant)) / 2.0;
            k2 = (-SecondEqualisedCoef - sqrt(discriminant)) / 2.0;

            n1 = FirstPointCoord[1] - k1 * FirstPointCoord[0];
            n2 = FirstPointCoord[1] - k2 * FirstPointCoord[0];

            std::cout << "The first tangent equation is: " << "y = " << k1 << "x + " << n1 << std::endl;
            std::cout << "The second tangent equation is: " << "y = " << k2 << "x + " << n2 << std::endl;
        }
    }
}

void FindInterPointBetwParAndLine(double lineOne[3], double ParabolaCoef[3]) {
    //Dx^2 + (E + A / B)x + (F + C / B) = 0
    double discriminant = (ParabolaCoef[1] + (lineOne[0] / lineOne[1])) * (ParabolaCoef[1] + (lineOne[0] / lineOne[1])) - (4 * ParabolaCoef[0] * (ParabolaCoef[2] + (lineOne[2] / lineOne[1])));
    double FirstPointCoord[2];
    double SecondPointCoord[2];

    if (lineOne[1] == 0) {
        FirstPointCoord[0] = -lineOne[2];
        FirstPointCoord[1] = ParabolaCoef[0] * FirstPointCoord[0] * FirstPointCoord[0] + ParabolaCoef[1] * FirstPointCoord[0] + ParabolaCoef[2];

        std::cout << "The coordinates of the intersection point is: " << '(' << FirstPointCoord[0] << ", " << FirstPointCoord[1] << ')' << std::endl;
    }

    FirstPointCoord[0] = (-(ParabolaCoef[1] + (lineOne[0] / lineOne[1])) + sqrt(discriminant)) / (2 * ParabolaCoef[0]);
    SecondPointCoord[0] = (-(ParabolaCoef[1] + (lineOne[0] / lineOne[1])) - sqrt(discriminant)) / (2 * ParabolaCoef[0]);
    FirstPointCoord[1] = (ParabolaCoef[0] * FirstPointCoord[0] * FirstPointCoord[0]) + ParabolaCoef[1] * FirstPointCoord[0] + ParabolaCoef[2];
    SecondPointCoord[1] = (ParabolaCoef[0] * SecondPointCoord[0] * SecondPointCoord[0]) + ParabolaCoef[1] * SecondPointCoord[0] + ParabolaCoef[2];

    if (discriminant < 0) {
        std::cout << "There are no intersection points." << std::endl;
    }
    else if (discriminant > 0) {
        std::cout << "The coordinates of the first intersection point are: " << '(' << FirstPointCoord[0] << ", " << FirstPointCoord[1] << ')' << std::endl;
        std::cout << "The coordinates of the second intersection point are: " << '(' << SecondPointCoord[0] << ", " << SecondPointCoord[1] << ')' << std::endl;
    }
    else if (discriminant == 0) {
        FirstPointCoord[0] = (-(ParabolaCoef[1] + lineOne[0] / lineOne[1]) / (2 * ParabolaCoef[0]));
        FirstPointCoord[1] = 0;
        std::cout << "The coordinates of the intersection point is: " << '(' << FirstPointCoord[0] << ", " << FirstPointCoord[1] << ')' << std::endl;
    }
}

void PrintParabolaEquation(double FirstLineFirstCoef, double FirstLineSecondCoef, double FirstLineThirdCoef) {
    std::cout << FirstLineFirstCoef << "x^2 + " << FirstLineSecondCoef << "x + " << FirstLineThirdCoef << " = y";
}

//(xCoordinate,yCoordinate) -> the point's coordinates A,B,C -> the parabolla's coefficients (yCoordinate = A*xCoordinate*xCoordinate + B*xCoordinate + C)
bool IsThePointOnTheParabola(double FirstXCoord, double SecondXCoord, double FirstLineFirstCoef, double FirstLineSecondCoef, double FirstLineThirdCoef) {
    return (CustomFabs(FirstLineFirstCoef * FirstXCoord * FirstXCoord + FirstLineSecondCoef * FirstXCoord + FirstLineThirdCoef - SecondXCoord) < MIN);
}
