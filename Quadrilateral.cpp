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
* file with all needed quadrilateral functions
*
*/

#include <iostream>
#include "Lines.h"

double DeterminantCalculator(double lineOne[3], double lineTwo[3], double lineThree[3]) {
    double positives = (lineOne[0] * lineTwo[1] * lineThree[2]) + (lineOne[1] * lineTwo[2] * lineThree[0]) + (lineOne[2] * lineTwo[0] * lineThree[1]);
    double negatives = (lineOne[2] * lineTwo[1] * lineThree[0]) + (lineOne[1] * lineTwo[0] * lineThree[2]) + (lineOne[0] * lineTwo[2] * lineThree[1]);
    return positives - negatives;
}

bool IsThereACommonIntersectionPoint(double lineOne[3], double lineTwo[3], double lineThree[3]) {
    double determinant = DeterminantCalculator(lineOne, lineTwo, lineThree);
    return determinant > -10e-12 && determinant < 10e-12;
}

bool AreFourSidesEqual(double FirstSide, double SecondSide, double ThirdSide, double FourthSide) {
    return (FirstSide == SecondSide == ThirdSide == FourthSide);
}

void QuadrilateralTypes(double QuadrilateralEquations[4][3]) {
    double ParallelLinesHolder[2][2] = { 0 };
    size_t counter = 0;

    for (size_t i = 0; i < 4; i++) {
        for (size_t j = i + 1; j < 4; j++) {
            if (TwoLinesAreParallel(QuadrilateralEquations[i], QuadrilateralEquations[j])) {
                ParallelLinesHolder[counter][0] = i;
                ParallelLinesHolder[counter][1] = j;
                counter++;
            }
        }
    }

    if (ParallelLinesHolder[1][0] == 0) {
        std::cout << "That is a trapezoid." << std::endl << std::endl;
    }
    else {
        double InterPointsHolder[4][2];
        int FirstParalelLine = ParallelLinesHolder[0][0];
        int SecondParalelLine = ParallelLinesHolder[0][1];

        int counter = 0;
        // 0,0 -> 1,0 ; 0,1 -> 1,0 ; 0,0 -> 1,1 ; 0,1 -> 1,1
        for (int i = 0; i < 4; i++) {
            if (ParallelLinesHolder[0][0] != i && ParallelLinesHolder[0][1] != i) {
                FindIntersectionPoint(QuadrilateralEquations[i], QuadrilateralEquations[FirstParalelLine], InterPointsHolder[counter++]);
                FindIntersectionPoint(QuadrilateralEquations[i], QuadrilateralEquations[SecondParalelLine], InterPointsHolder[counter++]);
            }
        }
        //first line of the first two parralel ones
        double SideOneLength = sqrt(pow(InterPointsHolder[1][0] - InterPointsHolder[0][0], 2) + pow(InterPointsHolder[1][1] - InterPointsHolder[0][1], 2));
        //second line of the first two parralel ones
        double SideTwoLength = sqrt(pow(InterPointsHolder[3][0] - InterPointsHolder[2][0], 2) + pow(InterPointsHolder[3][1] - InterPointsHolder[2][1], 2));
        //first line of the second two parralel ones
        double SideThreeLength = sqrt(pow(InterPointsHolder[2][0] - InterPointsHolder[0][0], 2) + pow(InterPointsHolder[2][1] - InterPointsHolder[0][1], 2));
        //second line of the second two parralel ones
        double SideFourLength = sqrt(pow(InterPointsHolder[3][0] - InterPointsHolder[1][0], 2) + pow(InterPointsHolder[3][1] - InterPointsHolder[1][1], 2));

        double FirstDiagonal = sqrt(pow(InterPointsHolder[3][0] - InterPointsHolder[0][0], 2) + pow(InterPointsHolder[3][1] - InterPointsHolder[0][1], 2));
        double SecondDiagonal = sqrt(pow(InterPointsHolder[2][0] - InterPointsHolder[1][0], 2) + pow(InterPointsHolder[2][1] - InterPointsHolder[1][1], 2));

        if (AreFourSidesEqual(SideOneLength, SideTwoLength, SideThreeLength, SideFourLength) && (FirstDiagonal == SecondDiagonal)) {
            std::cout << "That is a square." << std::endl << std::endl;
        }
        else if ((SideOneLength == SideTwoLength && SideThreeLength == SideFourLength) && (FirstDiagonal == SecondDiagonal)) {
            std::wcout << "That is a rectangle." << std::endl << std::endl;
        }
        else if (AreFourSidesEqual(SideOneLength, SideTwoLength, SideThreeLength, SideFourLength)) {
            std::cout << "That is a rhombus." << std::endl << std::endl;
        }
        else {
            std::cout << "That is a parallelogram." << std::endl;
        }
    }
}

bool CanAQuadrilateralBeFormed(double QuadrilateralEquations[4][3]) {
    size_t amountOfParallelLines = 1;

    for (size_t i = 0; i < 3; i++) {
        for (size_t j = i + 1; j < 3; j++) {
            if (TwoLinesAreParallel(QuadrilateralEquations[i], QuadrilateralEquations[j])) {
                amountOfParallelLines++;
            }
            if (TwoLinesAreMatching(QuadrilateralEquations[i], QuadrilateralEquations[j])) {
                return false;
            }
            if (amountOfParallelLines > 2) {
                return false;
            }
        }
    }
    //checking if three lines intersect in one point => if they do, there cannot be a quadrilateral
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = i + 1; j < 4; j++) {
            for (size_t k = j + 1; k < 4; k++) {
                if (IsThereACommonIntersectionPoint(QuadrilateralEquations[i], QuadrilateralEquations[j], QuadrilateralEquations[k])) {
                    return false;
                }
            }
        }
    }
    return true;
}
