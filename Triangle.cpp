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
* file, containing all triangle functions needed
*
*/

#include <iostream>
#include "Lines.h"

bool IsATriangle(double FirstPointCoord[2], double SecondPointCoord[2], double ThirdPointCoord[2]) {
    return ((SecondPointCoord[0] - FirstPointCoord[0]) * (ThirdPointCoord[1] - FirstPointCoord[1]) - (SecondPointCoord[1] - FirstPointCoord[1]) * (ThirdPointCoord[0] - FirstPointCoord[0])) != 0;
}

void HeightEquations(double FirstXCoord, double FirstYCoord, double SecondXCoord, double SecondYCoord, double ThirdXCoord, double ThirdYCoord) {
    double FirstAngleCoef =  (FirstXCoord - SecondXCoord) / (SecondYCoord - FirstYCoord);
    double SecondAngleCoef = (FirstXCoord - ThirdXCoord) / (ThirdYCoord - FirstYCoord);
    double ThirdAngleCoef = (SecondXCoord - ThirdXCoord) / (ThirdYCoord - SecondYCoord);

    if (((SecondYCoord - FirstYCoord) != 0) && ((ThirdYCoord - SecondYCoord) != 0) && ((ThirdYCoord - FirstYCoord) != 0)) {

        std::cout << "The equation of the first height is: ";
        FindAngleCoefficientEquation(ThirdXCoord, ThirdYCoord, FirstAngleCoef);
        std::cout << std::endl;

        std::cout << "The equation of the second height is: ";
        FindAngleCoefficientEquation(FirstXCoord, FirstYCoord, SecondAngleCoef);
        std::cout << std::endl;

        std::cout << "The equation of the third height is: ";
        FindAngleCoefficientEquation(SecondXCoord, SecondYCoord, ThirdAngleCoef);
        std::cout << std::endl << std::endl;
    }
}

void MedianEquations(double FirstXCoord, double FirstYCoord, double SecondXCoord, double SecondYCoord, double ThirdXCoord, double ThirdYCoord) {
    double XofFirstMidPoint = ((FirstXCoord + SecondXCoord) / 2);
    double YofFirstMidPoint = ((FirstYCoord + SecondYCoord) / 2);

    double XofSecondMidPoint = ((FirstXCoord + ThirdXCoord) / 2);
    double YofSecondMidPoint = ((FirstYCoord + ThirdYCoord) / 2);

    double XofThirdMidPoint = ((ThirdXCoord + SecondXCoord) / 2);
    double YofThirdMidPoint = ((ThirdYCoord + SecondYCoord) / 2);

    std::cout << "The equation of the first median is: ";
    PrintLineEquationWithTwoPoints(ThirdXCoord, ThirdYCoord, XofFirstMidPoint, YofFirstMidPoint);
    std::cout << std::endl;

    std::cout << "The equation of the second median is: ";
    PrintLineEquationWithTwoPoints(SecondXCoord, SecondYCoord, XofSecondMidPoint, YofSecondMidPoint);
    std::cout << std::endl;

    std::cout << "The equation of the third median is: ";
    PrintLineEquationWithTwoPoints(FirstXCoord, FirstYCoord, XofThirdMidPoint, YofThirdMidPoint);
    std::cout << std::endl << std::endl;
}

void SimetralEquations(double FirstXCoord, double FirstYCoord, double SecondXCoord, double SecondYCoord, double ThirdXCoord, double ThirdYCoord) {
    double FirstAngleCoef = (FirstXCoord - SecondXCoord) / (SecondYCoord - FirstYCoord);
    double SecondAngleCoef = (FirstXCoord - ThirdXCoord) / (ThirdYCoord - FirstYCoord);
    double ThirdAngleCoef = (SecondXCoord - ThirdXCoord) / (ThirdYCoord - SecondYCoord);

    double XofFirstMidPoint = ((FirstXCoord + SecondXCoord) / 2);
    double YofFirstMidPoint = ((FirstYCoord + SecondYCoord) / 2);

    double XofSecondMidPoint = ((FirstXCoord + ThirdXCoord) / 2);
    double YofSecondMidPoint = ((FirstYCoord + ThirdYCoord) / 2);

    double XofThirdMidPoint = ((ThirdXCoord + SecondXCoord) / 2);
    double YofThirdMidPoint = ((ThirdYCoord + SecondYCoord) / 2);

    std::cout << "The equation of the first simetral is: ";
    FindAngleCoefficientEquation(XofFirstMidPoint, YofFirstMidPoint, FirstAngleCoef);
    std::cout << std::endl;

    std::cout << "The equation of the second simetral is: ";
    FindAngleCoefficientEquation(XofSecondMidPoint, YofSecondMidPoint, SecondAngleCoef);
    std::cout << std::endl;

    std::cout << "The equation of the third simetral is: ";
    FindAngleCoefficientEquation(XofThirdMidPoint, YofThirdMidPoint, ThirdAngleCoef);
    std::cout << std::endl << std::endl;
}

