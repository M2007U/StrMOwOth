//version 2024.1124.0118

#pragma once

#include <iostream>
#include <iomanip>

#include <stdlib.h>
#include <cstdlib>

#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include <cstring>
#include <cctype>

#include <cmath>
#include <math.h>

#include <typeinfo>
#include <sys/types.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "FOwOFunctions_2024.cpp"

using namespace std;

class StrMOwOth
{
    public:

    FOwO fowo;

    vector<char> CharracterSet = {'0','1','2','3','4','5','6','7','8','9'}; //the set of charracters to represent quantities of powers of base
    char CharracterDot = '.'; //the charracter to represent the decimal point
    char CharracterNeg = '-';//the charracter to represent the negative sign
    vector<char> CharracterMechanism = {'#'}; //a set of charracters used for arithmetic mechanisms

    bool isDebug = false;
    string ResultIfError = "error";


    string Charracter_Shorthand_Set_Zero()
    {
        return fowo.strOwOng.cOwOnvert.charToString(CharracterSet[0]);
    }

    string Charracter_Shorthand_Set(int Index)
    {
        return fowo.strOwOng.cOwOnvert.charToString(CharracterSet[Index]);
    }

    string Charracter_Shorthand_Dot()
    {
        return fowo.strOwOng.cOwOnvert.charToString(CharracterDot);
    }

    string Charracter_Shorthand_Neg()
    {
        return fowo.strOwOng.cOwOnvert.charToString(CharracterNeg);
    }

    string Charracter_Shorthand_Mechanism(int Index)
    {
        return fowo.strOwOng.cOwOnvert.charToString(CharracterMechanism[Index]);
    }



    void Charracter_Set_Preset(int InBase)
    {
        switch (InBase)
        {
            case 2      : CharracterSet = {'0','1'}; break;
            case 10     : CharracterSet = {'0','1','2','3','4','5','6','7','8','9'}; break;
            case 16     : CharracterSet = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; break;
            default: break;
        }
    }



    int Number_IntLength(string InString)
    {
        //12345.6789

        int index = 0;
        int count = 0;

        while(InString.at(index) == CharracterSet[0])
        {
            index++;
        }
        
        while(InString.at(index) != CharracterDot && index < InString.length())
        {
            count++;
            index++;
        }

        return count;
    }

    int Number_FracLength(string InString, bool InIncludeTailingZeros)
    {
        if (fowo.strOwOng.dOwOtect.FindCharPos(InString,CharracterDot,'r') == -1)
        {
            return 0;
        }

        int index = InString.length() - 1;
        int count = 0;

        if (InIncludeTailingZeros == false)
        {
            while(InString.at(index) == CharracterSet[0])
            {
                index--;
            }
        }
        
        while(InString.at(index) != CharracterDot && -1 < index)
        {
            count++;
            index--;
        }

        return count;
    }
    
    string Number_CleanZeros(string InString)
    {
        if (isDebug)
        {
            cout << "---- ---- ---- ---- ---- ---- ---- ---- CLEAN ZERO START" << endl;
            cout << " ---- " << endl << "Plate : rec : " << InString << endl;
        }

        
        // STEP 1 ---- ---- ---- ---- decimal point giving

        string Plate = InString;

        if (fowo.strOwOng.dOwOtect.FindCharPos(Plate,CharracterDot,'l') == -1)
        {
            Plate = Plate + CharracterDot;
        }

        if (isDebug){cout << "Plate : " << Plate << endl;}

        

        // STEP 2 ---- ---- ---- ---- crunching iteration

        //#-000123000.000456000#

        //the main idea of this function is to attach both sides with a "#"
        //for every iteration,
        //if a "h0" is found, replace it with a "h"
        //if a "0h" is found, replace it with a "h"
        //if a "-0" is found, replace it with a "-"

        Plate =  Charracter_Shorthand_Mechanism(0) + Plate + Charracter_Shorthand_Mechanism(0);

        if (isDebug){cout << "Plate : " << Plate << endl;}
        
        string konst_hn0d = Charracter_Shorthand_Mechanism(0) + Charracter_Shorthand_Neg() + Charracter_Shorthand_Set_Zero() + Charracter_Shorthand_Dot();

        string konst_h0d = Charracter_Shorthand_Mechanism(0) + Charracter_Shorthand_Set_Zero() + Charracter_Shorthand_Dot();
        string konst_ndh = Charracter_Shorthand_Neg() + Charracter_Shorthand_Dot() + Charracter_Shorthand_Mechanism(0);
        string konst_hdh = Charracter_Shorthand_Mechanism(0) + Charracter_Shorthand_Dot() + Charracter_Shorthand_Mechanism(0);

        string konst_n0 = Charracter_Shorthand_Neg() + Charracter_Shorthand_Set_Zero();
        string konst_h0 = Charracter_Shorthand_Mechanism(0) + Charracter_Shorthand_Set_Zero();
        string konst_0h = Charracter_Shorthand_Set_Zero() + Charracter_Shorthand_Mechanism(0);
        string konst_dh = Charracter_Shorthand_Dot() + Charracter_Shorthand_Mechanism(0);
        string konst_hd = Charracter_Shorthand_Mechanism(0) + Charracter_Shorthand_Dot() ;
        
        
        
        bool JobDone = false;

        while(JobDone == false)
        {
            int pos_hn0d = fowo.strOwOng.dOwOtect.containsString(Plate,konst_hn0d,'l');

            int pos_h0d = fowo.strOwOng.dOwOtect.containsString(Plate,konst_h0d,'l');
            int pos_ndh = fowo.strOwOng.dOwOtect.containsString(Plate,konst_ndh,'l');
            int pos_hdh = fowo.strOwOng.dOwOtect.containsString(Plate,konst_hdh,'l');

            int pos_n0 = fowo.strOwOng.dOwOtect.containsString(Plate,konst_n0,'l');
            int pos_h0 = fowo.strOwOng.dOwOtect.containsString(Plate,konst_h0,'l');
            int pos_0h = fowo.strOwOng.dOwOtect.containsString(Plate,konst_0h,'l');
            int pos_dh = fowo.strOwOng.dOwOtect.containsString(Plate,konst_dh,'l');
            int pos_hd = fowo.strOwOng.dOwOtect.containsString(Plate,konst_hd,'l');
            
            

            if (isDebug){cout << "-" << endl << "Plate : bfr : " << Plate << endl;}

            if (pos_n0 == -1 && pos_h0 == -1 && pos_0h == -1 && pos_dh == -1 && pos_hd == -1 && pos_ndh == -1 && pos_hn0d == -1 && pos_hdh == -1)
            {
                JobDone = true;
            }
            else if (pos_hn0d != -1)
            {
                // #-0. -> -0.
                Plate = fowo.strOwOng.mOwOnip.subStringReplace(Plate,konst_hn0d,Charracter_Shorthand_Neg() + Charracter_Shorthand_Set_Zero() + Charracter_Shorthand_Dot());
            }
            else if (pos_h0d != -1)
            {
                // #0. -> 0.
                Plate = fowo.strOwOng.mOwOnip.subStringReplace(Plate,konst_h0d,Charracter_Shorthand_Set_Zero() + Charracter_Shorthand_Dot());
            }
            else if (pos_ndh != -1)
            {
                // -.# -> -0.# -> 0
                Plate = fowo.strOwOng.mOwOnip.subStringReplace(Plate,konst_ndh,Charracter_Shorthand_Set_Zero());
            }
            else if (pos_hdh != -1)
            {
                // #.# -> 0
                Plate = fowo.strOwOng.mOwOnip.subStringReplace(Plate,konst_ndh,Charracter_Shorthand_Set_Zero());
            }
            else if (pos_n0 != -1)
            {
                // -0 -> -
                Plate = fowo.strOwOng.mOwOnip.subStringReplace(Plate,konst_n0,Charracter_Shorthand_Neg());
            }
            else if (pos_h0 != -1)
            {
                // #0 -> #
                Plate = fowo.strOwOng.mOwOnip.subStringReplace(Plate,konst_h0,Charracter_Shorthand_Mechanism(0));
            }
            else if (pos_0h != -1)
            {
                // 0# -> #
                Plate = fowo.strOwOng.mOwOnip.subStringReplace(Plate,konst_0h,Charracter_Shorthand_Mechanism(0));
            }
            else if (pos_dh != -1)
            {
                // .# -> vanish
                Plate = fowo.strOwOng.mOwOnip.subStringReplace(Plate,konst_dh,"");
            }
            if (pos_hd != -1)
            {
                // #. -> 0.
                Plate = fowo.strOwOng.mOwOnip.subStringReplace(Plate,konst_hd,Charracter_Shorthand_Set_Zero() + Charracter_Shorthand_Dot());
            }

            if (isDebug){cout << "Plate : aft : " << Plate << endl;}
        }

        // STEP 3 ---- ---- ---- ---- remove hashtags fix

        //there might be left over hashtags
        //there could be 2 #s
        //there could be 1 #
        if (Plate == Charracter_Shorthand_Mechanism(0) + Charracter_Shorthand_Mechanism(0))
        {
            if (isDebug){cout << "Plate : is ## : return 0" << endl;}
            return "0";
        }
        else if (Plate == Charracter_Shorthand_Mechanism(0))
        {
            if (isDebug){cout << "Plate : is # : return 0" << endl;}
            return "0";
        }
        else if (Plate == Charracter_Shorthand_Mechanism(0) + Charracter_Shorthand_Neg())
        {
            if (isDebug){cout << "Plate : is #- : return 0" << endl;}
            return "0";
        }
        else if (Plate.length() > 1)
        {
            if (Plate.at(0) == CharracterMechanism[0]){Plate = Number_Strip(Plate,'h');}
            if (Plate.at(Plate.length()-1) == CharracterMechanism[0]){Plate = Number_Strip(Plate,'t');}
        }

        if (isDebug){cout << "Plate : " << Plate << endl;}

        // STEP 4 ---- ---- ---- ---- "-.456"

        //sometimes we will have the situation mentioned above
        if (fowo.strOwOng.dOwOtect.containsString(Plate,Charracter_Shorthand_Neg() + Charracter_Shorthand_Dot(),'l') != -1)
        {
            // -.123 -> -0.123
            Plate = fowo.strOwOng.mOwOnip.subStringReplace(Plate, Charracter_Shorthand_Neg() + Charracter_Shorthand_Dot(), Charracter_Shorthand_Neg() + Charracter_Shorthand_Set_Zero() + Charracter_Shorthand_Dot());
        }

        if (isDebug){cout << "Plate : ret : " << Plate << endl;}

        if (isDebug)
        {
            cout << "---- ---- ---- ---- ---- ---- ---- ---- CLEAN ZERO END" << endl;
        }


        return Plate;
         
    }

    string Number_GetAbs (string InString)
    {
        if (InString.length() > 0)
        {
            if (InString.at(0) == '-')
            {
                if (InString.length() == 1)
                {
                    return Charracter_Shorthand_Set_Zero();
                }
                else
                {
                    return fowo.strOwOng.mOwOnip.trim_Safe(InString, 1, InString.length()-1);
                }
            }
            else
            {
                return InString;
            }
        }
        else
        {
            return Charracter_Shorthand_Set_Zero();
        }

        return ResultIfError;
    }

    string Number_GetBase ()
    {
        //give "10", in base ten, is ten, in base2, is 2, in base16 , is 16
        return Charracter_Shorthand_Set(1) + Charracter_Shorthand_Set(0);
    }



    char Number_GetLastChar(string InString)
    {
        if (InString == "")
        {
            return '\0';
        }
        else
        {
            return InString.at(InString.length()-1);
        }
    }

    string Number_Strip(string InString, char InHeadOrTail)
    {
        if (InString.length() > 1)
        {
            if (InHeadOrTail == 't')
            {
                return fowo.strOwOng.mOwOnip.trim_Safe(InString,0,InString.length()-2);
            }
            else if (InHeadOrTail == 'h')
            {
                return fowo.strOwOng.mOwOnip.trim_Safe(InString,1,InString.length()-1);
            }
            else
            {
                return "";
            }  
        }
        else
        {
            return "";
        }
    }

    string Number_IsPosIsNeg(string InString)
    {
        if (InString.at(0) != '-' || InString.at(0) == '+')
        {
            return "+";
        }
        else if (InString.at(0) == '-')
        {
            return "-";
        }

        return ResultIfError;
    }

    string Number_Compare_Abs(string InA, string InB)
    {
        //WARNING : both InA and InB must be positive
        // aaaa.aaa00000
        // bbbb.bbbbbbbb

        string PlateA = Number_CleanZeros(InA);
        string PlateB = Number_CleanZeros(InB);

        if (fowo.strOwOng.dOwOtect.FindCharPos(PlateA,CharracterDot,'l') == -1){PlateA = PlateA + Charracter_Shorthand_Dot();}
        if (fowo.strOwOng.dOwOtect.FindCharPos(PlateB,CharracterDot,'l') == -1){PlateB = PlateB + Charracter_Shorthand_Dot();}

        while(Number_FracLength(PlateA,true) != Number_FracLength(PlateB,true))
        {
            if (Number_FracLength(PlateA,true) < Number_FracLength(PlateB,true))
            {
                PlateA = PlateA + CharracterSet[0];
            }
            else if (Number_FracLength(PlateA,true) > Number_FracLength(PlateB,true))
            {
                PlateB = PlateB + CharracterSet[0];
            }
        }

        if (PlateA.length() > PlateB.length())
        {
            return "A>B";
        }
        else if (PlateA.length() < PlateB.length())
        {
            return "A<B";
        }
        else
        {
            while(PlateA.length() > 0 && PlateB.length() > 0)
            {
                if ( fowo.vectOwOr.FindObjPos(CharracterSet,PlateA.at(0),'l') > fowo.vectOwOr.FindObjPos(CharracterSet,PlateB.at(0),'l') )
                {
                    return "A>B";
                }
                else if ( fowo.vectOwOr.FindObjPos(CharracterSet,PlateA.at(0),'l') < fowo.vectOwOr.FindObjPos(CharracterSet,PlateB.at(0),'l') )
                {
                    return "A<B";
                }
                else
                {
                    PlateA = Number_Strip(PlateA,'h');
                    PlateB = Number_Strip(PlateB,'h');
                }
            }

            return "A=B";
        }

        return ResultIfError;

    }

    string Number_Compare(string InA, string InB)
    {
        if (Number_IsPosIsNeg(InA) == "-" && Number_IsPosIsNeg(InB) == "+")
        {
            return "A<B";
        }
        else if (Number_IsPosIsNeg(InA) == "+" && Number_IsPosIsNeg(InB) == "-")
        {
            return "A>B";
        }
        else if (Number_IsPosIsNeg(InA) == "-" && Number_IsPosIsNeg(InB) == "-")
        {
            string tempResult = Number_Compare_Abs( Number_GetAbs(InA), Number_GetAbs(InB));

            if (tempResult == "A>B"){return "A<B";}
            else if (tempResult == "A<B") {return "A>B";}
            else {return "A=B";}
        }
        else
        {
            return Number_Compare_Abs(InA,InB);
        }

        return ResultIfError;
    }

    string Number_BorrowFlip(string InA, int InPosition)
    {
        //if we ended up with the following situation :
        //  xxxx.xxxx00000
        //-   yy.yyyyyyyyy
        //then we can drop both Plates by 0.000...0001
        //to convert them into
        //  xxxx.xxxw99999
        //-   yy.yyyyyyyyx
        //now we can do the math easily

        string PlateA = InA;

        int pointer = InPosition;

        if (PlateA.length() <= InPosition)
        {
            cout << fowo.cOwOut.ConsoleQuick("error","Position is out of range, will not flip") << endl;
            return InA;
        }

        if (PlateA.at(pointer) == CharracterDot)
        {
            cout << fowo.cOwOut.ConsoleQuick("error","Position is decimal point, will not flip") << endl;
            return InA;
        }

        if (PlateA.at(pointer) != CharracterSet[0] && fowo.vectOwOr.FindObjPos(CharracterSet,PlateA.at(pointer),'l') != -1)
        {
            PlateA.at(pointer) = CharracterSet[fowo.vectOwOr.FindObjPos(CharracterSet,PlateA.at(pointer),'l') - 1];
            return PlateA;
        }


        while(PlateA.at(pointer) == CharracterSet[0] || PlateA.at(pointer) == CharracterDot)
        {
            if (PlateA.at(pointer) == CharracterSet[0])
            {
                PlateA.at(pointer) = CharracterSet[ CharracterSet.size()-1 ];
                pointer--;
            }
            else if (PlateA.at(pointer) == CharracterDot)
            {
                pointer--;
            }
        }
        PlateA.at(pointer) = CharracterSet[fowo.vectOwOr.FindObjPos(CharracterSet,PlateA.at(pointer),'l') - 1];

        return PlateA;
    }



    string Addition (string InA, string InB)
    {
        //this will only work if InA and InB are positive

        if (isDebug)
        {
            cout << "---- ---- ---- ---- ---- ---- ---- ---- ADDITION START" << endl;
        }

        string PlateA = Number_CleanZeros(InA);
        string PlateB = Number_CleanZeros(InB);
        string PlateR = Charracter_Shorthand_Set_Zero() ;

        if (isDebug)
        {
            cout << "---- ---- ---- ---- Clean Zeros" << endl;
            cout << "plate A : " << PlateA << endl;
            cout << "plate B : " << PlateB << endl;
            cout << "plate R : " << PlateR << endl;
        }

        //make both Plates have the same fraction length
        //make sure both have decimal points
        if (fowo.strOwOng.dOwOtect.FindCharPos(PlateA,CharracterDot,'l') == -1)
        {
            PlateA = PlateA + Charracter_Shorthand_Dot();
        }
        if (fowo.strOwOng.dOwOtect.FindCharPos(PlateB,CharracterDot,'l') == -1)
        {
            PlateB = PlateB + Charracter_Shorthand_Dot();
        }
        while(Number_FracLength(PlateA,false) != Number_FracLength(PlateB,false))
        {
            if (Number_FracLength(PlateA,false) > Number_FracLength(PlateB,false))
            {
                PlateR = Number_GetLastChar(PlateA) + PlateR;
                PlateA = Number_Strip(PlateA,'t');
            }
            else if (Number_FracLength(PlateA,false) < Number_FracLength(PlateB,false))
            {
                PlateR = Number_GetLastChar(PlateB) + PlateR;
                PlateB = Number_Strip(PlateB,'t');
            }
        }

        if (isDebug)
        {
            cout << "---- ---- ---- ---- Fraction Length Adjustments" << endl;
            cout << "plate  A : " << PlateA << endl;
            cout << "plate  B : " << PlateB << endl;
        }

        int arith_val_A = 0; //from PlateA
        int arith_val_B = 0; //from PlateB
        int arith_val_Cd = 0; //from previous carry
        int arith_val_O = 0; //ones places for the result
        int arith_val_Cu = 0; //tens places for the result, carry to the next iteration

        while(PlateA.length() != 0 && PlateB.length() != 0)
        {
            if (Number_GetLastChar(PlateA) == CharracterDot && Number_GetLastChar(PlateB) == CharracterDot)
            {
                PlateR = Charracter_Shorthand_Dot() + PlateR;
                PlateA = Number_Strip(PlateA,'t');
                PlateB = Number_Strip(PlateB,'t');

                if (isDebug)
                {
                    cout << "---- ---- ---- ---- dot strip" << endl;
                    cout << "plate  A : " << PlateA << endl;
                    cout << "plate  B : " << PlateB << endl;
                    cout << "plate  R : " << PlateR << endl;
                }

            }
            else
            {
                arith_val_A = fowo.vectOwOr.FindObjPos(CharracterSet,Number_GetLastChar(PlateA),'l');
                arith_val_B = fowo.vectOwOr.FindObjPos(CharracterSet,Number_GetLastChar(PlateB),'l');

                if (arith_val_A == -1 || arith_val_B == -1)
                {
                    cout << "🚩here ?" << endl;
                    return ResultIfError;
                }

                arith_val_O = (arith_val_A + arith_val_B + arith_val_Cd) % CharracterSet.size();
                arith_val_Cu = (arith_val_A + arith_val_B + arith_val_Cd) / CharracterSet.size();

                PlateR = CharracterSet[arith_val_O] + PlateR;

                if (isDebug)
                {
                    cout << "---- ---- ---- ---- arith iteration" << endl;
                    cout << "plate  A : " << PlateA << endl;
                    cout << "plate  B : " << PlateB << endl;
                    cout << "arith  A : " << arith_val_A << endl;
                    cout << "arith  B : " << arith_val_B << endl;
                    cout << "arith Cd : " << arith_val_Cd << endl;
                    cout << "arith  O : " << arith_val_O << endl;
                    cout << "arith Cu : " << arith_val_Cu << endl;
                    cout << "plate  R : " << PlateR << endl;
                }
                
                //prepare for next iteration
                arith_val_Cd = arith_val_Cu;
                arith_val_Cu = 0;
                PlateA = Number_Strip(PlateA,'t');
                PlateB = Number_Strip(PlateB,'t');
            }
        }

        if (isDebug)
        {
            cout << "---- ---- ---- ---- PlateA or PlateB is now empty" << endl;
            cout << "plate  A : " << PlateA << endl;
            cout << "plate  B : " << PlateB << endl;
        }

        if (arith_val_Cd == 1) //are there carries left ?
        {
            if (PlateA.length() > 0)
            {
                PlateA = Addition(PlateA, fowo.strOwOng.cOwOnvert.charToString(CharracterSet[1]));
            }
            else if (PlateB.length() > 0)
            {
                PlateB = Addition(PlateB, fowo.strOwOng.cOwOnvert.charToString(CharracterSet[1]));
            }
            else
            {
                PlateA = fowo.strOwOng.cOwOnvert.charToString(CharracterSet[1]);
                PlateB = "";
            }
        }

        PlateR = PlateA + PlateB + PlateR;

        if (isDebug)
        {
            cout << "---- ---- ---- ---- ---- ---- ---- ---- ADDITION END" << endl;
        }

        return Number_CleanZeros(PlateR);        
    }

    string Addition_Safe(string InA, string InB)
    {
        string InAPosNeg = Number_IsPosIsNeg(InA);
        string InBPosNeg = Number_IsPosIsNeg(InB);

        //+B + +S = ok
        //+B + -S = ok
        //-B + +S = S - B
        //-B + -S = -B - S

        //+S + +B = ok
        //+S + -B = S - B
        //-S + +B = B - S
        //-S + -B = -S - B

        if (Number_Compare_Abs(InA,InB) == "A>B")
        {
            if (InAPosNeg == "+")
            {
                if (InBPosNeg == "+")
                {
                    return Addition(InA,InB);
                }
                else if (InBPosNeg == "-")
                {
                    return Subtraction(InA, Number_Strip(InB,'h') );
                }
            }
            else if (InAPosNeg == "-")
            {
                if (InBPosNeg == "+")
                {
                    return Subtraction_Safe(InB, Number_Strip(InA,'h'));
                }
                else if (InBPosNeg == "-")
                {
                    return Subtraction_Safe(InA, Number_Strip(InB,'h'));
                }
            }
        }
        else if (Number_Compare_Abs(InA,InB) == "A<B")
        {
            if (InAPosNeg == "+")
            {
                if (InBPosNeg == "+")
                {
                    return Addition(InA,InB);
                }
                else if (InBPosNeg == "-")
                {
                    return Subtraction_Safe(InA, Number_Strip(InB,'h'));
                }
            }
            else if (InAPosNeg == "-")
            {
                if (InBPosNeg == "+")
                {
                    return Subtraction_Safe(InB, Number_Strip(InA,'h') );
                }
                else if (InBPosNeg == "-")
                {
                    return Subtraction_Safe(InA, Number_Strip(InB,'h'));
                }
            }
        }
        else if (Number_Compare_Abs(InA,InB) == "A=B")
        {
            if (InAPosNeg == "+")
            {
                if (InBPosNeg == "+")
                {
                    return Addition(InA,InB);
                }
                else if (InBPosNeg == "-")
                {
                    return Charracter_Shorthand_Set_Zero();
                }
            }
            else if (InAPosNeg == "-")
            {
                if (InBPosNeg == "+")
                {
                    return Charracter_Shorthand_Set_Zero();
                }
                else if (InBPosNeg == "-")
                {
                    return Charracter_Shorthand_Neg() + Addition( Number_Strip(InA,'h'), Number_Strip(InB,'h'));
                }
            }
        }

        return ResultIfError;


    }

    string Subtraction (string InA, string InB)
    {
        //this will only work if
        //1. both InA and InB are positive
        //2. InA is greater or equal to InB

        if (isDebug)
        {
            cout << "---- ---- ---- ---- ---- ---- ---- ---- SUBTRACTION START" << endl;
        }

        //here we will assume that InA > InB
        

        string PlateA = Number_CleanZeros(InA);
        string PlateB = Number_CleanZeros(InB);
        string PlateR = "";

        if (isDebug)
        {
            cout << "---- ---- ---- ---- Cleaned Zeros" << endl;
            cout << "plate A : " << PlateA << endl;
            cout << "plate B : " << PlateB << endl;
        }

        //give the strings a decimal point if they do not have any
        if (fowo.strOwOng.dOwOtect.FindCharPos(PlateA,CharracterDot,'l') == -1){PlateA = PlateA + Charracter_Shorthand_Dot();}
        if (fowo.strOwOng.dOwOtect.FindCharPos(PlateB,CharracterDot,'l') == -1){PlateB = PlateB + Charracter_Shorthand_Dot();}

        if (isDebug)
        {
            cout << "---- ---- ---- ---- Given Decimal Dots" << endl;
            cout << "plate A : " << PlateA << endl;
            cout << "plate B : " << PlateB << endl;
        }

        //PAD the number with 0s which has a shorter frac length

        while(Number_FracLength(PlateA,true) != Number_FracLength(PlateB,true))
        {
            if (Number_FracLength(PlateA,true) < Number_FracLength(PlateB,true))
            {
                PlateA = PlateA + CharracterSet[0];
            }
            else if (Number_FracLength(PlateA,true) > Number_FracLength(PlateB,true))
            {
                PlateB = PlateB + CharracterSet[0];
            }
        }

        if (isDebug)
        {
            cout << "---- ---- ---- ---- Padded number with shorter FracLength" << endl;
            cout << "plate A : " << PlateA << endl;
            cout << "plate B : " << PlateB << endl;
        }


        int arith_val_A = 0;
        int arith_val_B = 0;
        int arith_val_requestBorrow = 0; //if in this iteration, we are borrowing from the next iteration
        int arith_val_O = 0;
        int arith_val_isBorrowed = 0; //if this iteration is borrowed by the previous iteration

        while(PlateB.length() > 0)
        {
            if (isDebug)
            {
                cout << "---- ---- ---- ---- Iteration START" << endl;
            }

            if (Number_GetLastChar(PlateA) == CharracterSet[0] && Number_GetLastChar(PlateB) != CharracterSet[0])
            {
                if (isDebug)
                {
                    cout << "---- ---- ---- ---- flip mechanism" << endl;
                    cout << "bef" << endl;
                    cout << "plate A : " << PlateA << endl;
                    cout << "plate B : " << PlateB << endl;
                }

                PlateA = Number_BorrowFlip(PlateA,PlateA.length()-1);
                PlateB = Number_BorrowFlip(PlateB,PlateB.length()-1);

                if (isDebug)
                {
                    cout << "---- ---- ---- ---- flip mechanism" << endl;
                    cout << "aft" << endl;
                    cout << "plate A : " << PlateA << endl;
                    cout << "plate B : " << PlateB << endl;
                }
            }
            else if (Number_GetLastChar(PlateA) == CharracterDot && Number_GetLastChar(PlateB) == CharracterDot)
            {
                if (isDebug)
                {
                    cout << "---- ---- ---- ---- decimal point" << endl;
                    cout << "bef" << endl;
                    cout << "plate A : " << PlateA << endl;
                    cout << "plate B : " << PlateB << endl;
                }

                PlateR = Charracter_Shorthand_Dot() + PlateR;
                PlateA = Number_Strip(PlateA,'t');
                PlateB = Number_Strip(PlateB,'t');

                if (isDebug)
                {
                    cout << "---- ---- ---- ---- decimal point" << endl;
                    cout << "aft" << endl;
                    cout << "plate A : " << PlateA << endl;
                    cout << "plate B : " << PlateB << endl;
                }
            }
            else
            {
                if (isDebug)
                {
                    cout << "---- ---- ---- ---- normal calculation" << endl;
                }

                arith_val_A = fowo.vectOwOr.FindObjPos(CharracterSet,Number_GetLastChar(PlateA),'l');
                arith_val_B = fowo.vectOwOr.FindObjPos(CharracterSet,Number_GetLastChar(PlateB),'l');

                if (isDebug)
                {
                    cout << "---- ---- ---- ---- Get Last CHarracter to Charracter set" << endl;
                    cout << "plate A : " << PlateA << "(" << PlateA.length() << ")" << endl;
                    cout << "plate B : " << PlateB << "(" << PlateB.length() << ")" << endl;
                    fowo.strOwOng.dOwOtect.PrintAscii(PlateA);
                    fowo.strOwOng.dOwOtect.PrintAscii(PlateB);
                    cout << "arith a : " << arith_val_A << endl;
                    cout << "arith b : " << arith_val_B << endl; 
                }

                if (arith_val_A == -1 || arith_val_B == -1)
                {
                    return ResultIfError;
                }

                //do we need to borrow from the next iteration
                if (arith_val_B > arith_val_A)
                {
                    if (PlateA.at(PlateA.length()-2) == CharracterDot)
                    {
                        //if the charrcetr on the left is a decimal point
                        PlateA = Number_BorrowFlip(PlateA,PlateA.length()-3);
                    }
                    else
                    {
                        //if the charracter on the left is a normal number
                        PlateA = Number_BorrowFlip(PlateA,PlateA.length()-2);
                    }
                    
                    arith_val_A += CharracterSet.size();
                }

                arith_val_O = arith_val_A - arith_val_B;

                PlateR = CharracterSet[arith_val_O] + PlateR;

                if (isDebug)
                {
                    cout << "---- ---- ---- ---- arith iteration" << endl;
                    cout << "plate A : " << PlateA << endl;
                    cout << "plate B : " << PlateB << endl;
                    cout << "arith A : " << arith_val_A << endl;
                    cout << "arith B : " << arith_val_B << endl;
                    cout << "arith O : " << arith_val_O << endl;
                    cout << "plate R : " << PlateR << endl;
                }

                //prepare for next iteration
                PlateA = Number_Strip(PlateA,'t');
                PlateB = Number_Strip(PlateB,'t');
            }

            if (isDebug)
            {
                cout << "---- ---- ---- ---- Iteration END" << endl;
            }
        }

        PlateR = PlateA + PlateR;

        if (isDebug)
        {
            cout << "---- ---- ---- ---- ---- ---- ---- ---- SUBTRACTION END" << endl;
        }

        return Number_CleanZeros(PlateR);
    }

    string Subtraction_Safe (string InA, string InB)
    {
        //takes care which ever is bigger in magnitude
        //and takes care which ever is pos or neg

        // +B - +S
        // +B - -S -> = +B + S
        // -B - +S -> = -(B+S)
        // -B - -S -> = -(B-S)

        // +S - +B -> = S - B = -(B-S)
        // +S - -B -> = S + B
        // -S - +B -> = -(S+B) 
        // -S - -B -> = -(S-B) = B-S
        
        if ( Number_Compare_Abs(InA,InB) == "A>B" )
        {
            if (Number_IsPosIsNeg(InA) == "+")
            {
                if (Number_IsPosIsNeg(InB) == "+")
                {
                    return Subtraction(InA,InB);
                }
                else if (Number_IsPosIsNeg(InB) == "-")
                {
                    return Addition(InA, Number_Strip(InB,'h'));
                }
            }
            else if (Number_IsPosIsNeg(InA) == "-")
            {
                if (Number_IsPosIsNeg(InB) == "+")
                {
                    return Charracter_Shorthand_Neg() + Addition(Number_Strip(InA,'h'),InB);
                }
                else if (Number_IsPosIsNeg(InB) == "-")
                {
                    return Charracter_Shorthand_Neg() + Subtraction(Number_Strip(InA,'h'), Number_Strip(InB,'h'));
                }
            }
        }
        else if (Number_Compare_Abs(InA,InB) == "A<B")
        {
            if (Number_IsPosIsNeg(InA) == "+")
            {
                if (Number_IsPosIsNeg(InB) == "+")
                {
                    return Charracter_Shorthand_Neg() + Subtraction(InB,InA);
                }
                else if (Number_IsPosIsNeg(InB) == "-")
                {
                    return Addition(InA, Number_Strip(InB,'h'));
                }
            }
            else if (Number_IsPosIsNeg(InA) == "-")
            {
                if (Number_IsPosIsNeg(InB) == "+")
                {
                    return Charracter_Shorthand_Neg() + Addition(Number_Strip(InA,'h'),InB);
                }
                else if (Number_IsPosIsNeg(InB) == "-")
                {
                    return Subtraction(Number_Strip(InB,'h'), Number_Strip(InA,'h'));
                }
            }
        }
        else if (Number_Compare_Abs(InA,InB) == "A=B")
        {
            return "0";
        }

        return ResultIfError;
    }

    string Multiplication (string InA, string InB)
    {
        //this will only work for positive numbers

        if (isDebug)
        {
            cout << "---- ---- ---- ---- ---- ---- ---- ---- MULTIPLICATION START" << endl;
        }

        // assume that we have the following :
        //     ABCDE = PlateA
        // *     XYZ = PlateB
        // ---------
        //     abcde = PlateS[0]
        //    abcde0 = PlateS[1]
        // + abcde00 = PlateS[2]
        // ---------
        //   pqrstuv = PlateR

        // STEP 0 ---- ---- ---- ---- prepare variables

        string PlateA = InA;
        string PlateB = InB;
        string PlateS = "";
        string PlateR = "";
        int TrueFracLengthA = Number_FracLength(InA,false);
        int TrueFracLengthB = Number_FracLength(InB,false);
        string PlateP = ""; //the final answer

        if (isDebug)
        {
            cout << "---- ---- ---- ---- Variable Prepare" << endl;
            cout << "PlateA : " << PlateA << endl;
            cout << "PlateB : " << PlateB << endl;
            cout << "FrLenA : " << TrueFracLengthA << endl;
            cout << "FrLenB : " << TrueFracLengthB << endl;
        }

        // STEP 1 ---- ---- ---- ---- remove extra zeros

        PlateA = Number_CleanZeros(PlateA);
        PlateB = Number_CleanZeros(PlateB);

        if (isDebug)
        {
            cout << "---- ---- ---- ---- Zero Cleaning" << endl;
            cout << "PlateA : " << PlateA << endl;
            cout << "PlateB : " << PlateB << endl;
        }

        // STEP 2 ---- ---- ---- ---- remove the decimal point

        PlateA = fowo.strOwOng.mOwOnip.subStringReplace(PlateA,Charracter_Shorthand_Dot(),"");
        PlateB = fowo.strOwOng.mOwOnip.subStringReplace(PlateB,Charracter_Shorthand_Dot(),"");

        if (isDebug)
        {
            cout << "---- ---- ---- ---- Remove decimal point" << endl;
            cout << "PlateA : " << PlateA << endl;
            cout << "PlateB : " << PlateB << endl;
        }

        

        // STEP 3 ---- ---- ---- ---- Check if any of the Input strings are empty, or just zeros

        if (PlateA == Charracter_Shorthand_Set_Zero() || PlateB == Charracter_Shorthand_Set_Zero())
        {
            return Charracter_Shorthand_Set_Zero();
        }

        

        // STEP 4 ---- ---- ---- ---- start doing the times table

        if (isDebug)
        {
            cout << "---- ---- ---- ---- TIME TABLE START" << endl;
            cout << "PlateA : " << PlateA << endl;
            cout << "PlateB : " << PlateB << endl;
            cout << "PlateS : " << PlateS << endl;
            cout << "PlateR : " << PlateR << endl;
        }

        int arith_a = 0; //from PlateA
        int arith_b = 0; //from PlateB
        int arith_o = 0; //the output
        int arith_c = 0; //the carry

        for(int i = PlateB.length()-1 ; 0 <= i ; i--)
        {
            arith_b = fowo.vectOwOr.FindObjPos(CharracterSet,PlateB.at(i),'l');
            arith_o = 0;
            arith_c = 0;

            PlateS = "";//get the substring ready
            for(int z = 0 ; z < PlateB.length() - 1 - i ; z++) //padding the zero
            {
                PlateS = PlateS + Charracter_Shorthand_Set_Zero();
            }

            for(int j = PlateA.length()-1 ; 0 <= j ; j--)
            {
                arith_a = fowo.vectOwOr.FindObjPos(CharracterSet,PlateA.at(j),'l');

                arith_o = arith_a * arith_b + arith_c; //arith_c is from the previous carry
                arith_c = arith_o / CharracterSet.size();
                arith_o = arith_o % CharracterSet.size();

                PlateS = CharracterSet[arith_o] + PlateS;

            }

            PlateS = CharracterSet[arith_c] + PlateS; //leftover carries

            if (isDebug)
            {
                cout << "Plate S : " << PlateS << endl;
            }

            PlateR = Addition(PlateR,PlateS);

            if (isDebug)
            {
                cout << "Plate R : " << PlateR << endl;
            }
        }


        
        

        //now PlateR has the sub answer, but not yet

        // STEP 5 ---- ---- ---- ---- put the decimal point back in

        // A : 00000.00000
        // B :   000.000
        //               V
        // R : 00000000000 00000000
        // P : 00000000000.00000000

        //here we have 2 situations : 
        //either PlateR.length > TrueFracLengthA + TrueFracLengthB, which is easy
        //or else PlateR.length <= TrueFracLengthA + TrueFracLengthB

        if ( TrueFracLengthA + TrueFracLengthB < PlateR.length() )
        {
            for(int i = PlateR.length()-1 ; 0 <= i ; i--)
            {
                if ( i == PlateR.length() - 1 - TrueFracLengthA - TrueFracLengthB )
                {
                    PlateP = "." + PlateP;
                }

                PlateP = PlateR.at(i) + PlateP;
            }
        }
        else if ( PlateR.length() <= TrueFracLengthA + TrueFracLengthB)
        {
            PlateP = PlateR;
            while(PlateP.length() < TrueFracLengthA + TrueFracLengthB)
            {
                PlateP = CharracterSet[0] + PlateP;
            }

            PlateP = Charracter_Shorthand_Set_Zero() + "." + PlateP;
        }

        return Number_CleanZeros(PlateP);

    }

    string Multiplication_Safe (string InA, string InB)
    {
        string InAPosNeg = Number_IsPosIsNeg(InA);
        string InBPosNeg = Number_IsPosIsNeg(InB);
        string InAAbs = Number_GetAbs(InA);
        string InBAbs = Number_GetAbs(InB);

        string AbsResult = Multiplication(InAAbs,InBAbs);

        if (InAPosNeg == InBPosNeg)
        {
            return Number_CleanZeros(AbsResult);
        }
        else
        {
            return Number_CleanZeros(Charracter_Shorthand_Neg() + AbsResult);
        }
    }
    
    string Division (string InA, string InB, int InDecimalPrecision)
    {

        //this will only work for positive integers

        if (isDebug)
        {
            cout << "---- ---- ---- ---- ---- ---- ---- ---- DIVISION START" << endl;
        }

        if (isDebug)
        {
            cout << "---- ---- ---- ---- CHECK IF 0" << endl;
        }

        if (Number_GetAbs(InB) == "0")
        {
            cout << fowo.cOwOut.ConsoleQuick("error","division by 0") << endl;
            return ResultIfError;
        }

        

        /*

        MAIN CONCEPT

        assume that we have the following setup and variables :
        the string to be divided : AAAAAA
        the string to divide : BBB
        a plate string AL // ALeft
        a plate string AR // ARight
        a plate string R //for our final answer
        a counter C //for our current indexed guess

        so far we have the following :

        string PlateAL = "";
        string PlateAR = InA;
        string PlateB = InB;
        string PlateR = "";
        int Counter = 0;

        now begin :

        1. is PlateAL big enough to be Subtracted by Plate B ?
            yes : goto step 2
            no  : pull the left most digit from PlateAR to PlateAL (if there are digits to get pulled) , export Counter to PlateR, Counter = 0,  go to step 1


        2. right now PlateAL is big enough to be subtracted by Plate B
            PlateAL = PlateAL - PlateB ;
            Counter++ ;
            goto step 1

        now update this to the following : 

        is PlateAL big enough to be Subtracted by Plate B ?
            yes : right now PlateAL is big enough to be subtracted by Plate B
            PlateAL = PlateAL - PlateB ;
            Counter++ ;
            no  : are there any digits to be pulled from PlateAR to PlateAL ?
                yes : pull the left most digit from PlateAR to PlateAL
                no  : export "." to PlateR ONLY if PlateR do not have a decimal point yet, pull a zero to PlateAL
                export Counter to PlateR;
                Counter = 0;
                have we reached our desired precision ? i.e. FracLength for PlateR is long enough
                    yes : we are done
                    no  : go to step 1

        now can be converted into code :

        bool JobDone = false;
        while(JobDone == false)
        {
            if (PlateAL is big enough to be Subtracted by Plate B ?)
            {
                yes : right now PlateAL is big enough to be subtracted by Plate B
                PlateAL = PlateAL - PlateB ;
                Counter++ ;
            }
            else
            {
                no  : borrow from the next digit
                
                if (are there any digits to be pulled from PlateAR to PlateAL ?)
                {
                    yes : pull the left most digit from PlateAR to PlateAL
                }
                else
                {
                    no  : export "." to PlateR ONLY if PlateR do not have a decimal point yet, pull a zero to PlateAL
                }
                
                export Counter to PlateR;
                Counter = 0;


                if (have we reached our desired precision ? i.e. FracLength for PlateR is long enough)
                {
                    yes : we are done
                    JobDone = true;
                }
                     
            }
            
        }

        */

        string PlateAL = "";
        string PlateAR = InA;
        string PlateB = InB;
        string PlateR = "";
        int Counter = 0;

        bool JobDone = false;
        while(JobDone == false)
        {
            if (isDebug)
            {
                cout << "---- ---- ---- ---- arith iteration start" << endl;
                cout << "PlateA : " << PlateAL << " | " << PlateAR << endl;
                cout << "PlateB : " << PlateB << endl;
                cout << "Count  : " << Counter << endl;
                cout << "PlateR : " << PlateR << endl;
            }

            if (Number_Compare_Abs(PlateAL,PlateB) == "A>B" || Number_Compare_Abs(PlateAL,PlateB) == "A=B" )
            {
                //yes : right now PlateAL is big enough to be subtracted by Plate B
                PlateAL = Subtraction(PlateAL,PlateB);
                Counter++ ;

                if (isDebug)
                {
                    cout << "---- ---- ---- ---- AL = AL - B , Counter++" << endl;
                    cout << "PlateA : " << PlateAL << " | " << PlateAR << endl;
                    cout << "PlateB : " << PlateB << endl;
                    cout << "Count  : " << Counter << endl;
                    cout << "PlateR : " << PlateR << endl;
                }

            }
            else
            {
                //no

                //export C to R
                PlateR = PlateR + Charracter_Shorthand_Set(Counter);
                Counter = 0;

                //borrow from the next digit        
                if (PlateAR.length() > 0 )
                {
                    //yes : pull the left most digit from PlateAR to PlateAL
                    PlateAL = PlateAL + PlateAR.at(0);
                    PlateAR = Number_Strip(PlateAR,'h');

                    if (isDebug)
                    {
                        cout << "---- ---- ---- ---- pulled from AR to AL" << endl;
                        cout << "PlateA : " << PlateAL << " | " << PlateAR << endl;
                        cout << "PlateB : " << PlateB << endl;
                        cout << "Count  : " << Counter << endl;
                        cout << "PlateR : " << PlateR << endl;
                    }
                }
                else
                {
                    //no  : export "." to PlateR ONLY if PlateR do not have a decimal point yet, pull a zero to PlateAL
                    if (fowo.strOwOng.dOwOtect.FindCharPos(PlateR, CharracterDot, 'l') == -1)
                    {
                        PlateR = PlateR + Charracter_Shorthand_Dot();

                        if (isDebug)
                        {
                            cout << "---- ---- ---- ---- decimal point added" << endl;
                            cout << "PlateA : " << PlateAL << " | " << PlateAR << endl;
                            cout << "PlateB : " << PlateB << endl;
                            cout << "Count  : " << Counter << endl;
                            cout << "PlateR : " << PlateR << endl;
                        }
                    }
                    PlateAL = PlateAL + Charracter_Shorthand_Set_Zero();

                    if (isDebug)
                    {
                        cout << "---- ---- ---- ---- AL added 0" << endl;
                        cout << "PlateA : " << PlateAL << " | " << PlateAR << endl;
                        cout << "PlateB : " << PlateB << endl;
                        cout << "Count  : " << Counter << endl;
                        cout << "PlateR : " << PlateR << endl;
                    }

                }
                
                

                if (isDebug)
                {
                    cout << "---- ---- ---- ---- export Counter to R" << endl;
                    cout << "PlateA : " << PlateAL << " | " << PlateAR << endl;
                    cout << "PlateB : " << PlateB << endl;
                    cout << "Count  : " << Counter << endl;
                    cout << "PlateR : " << PlateR << endl;
                }

                if ( Number_FracLength(PlateR,true) >=  InDecimalPrecision)
                {
                    //yes : we are done
                    JobDone = true;
                }
                     
            }
            
        }

        if (isDebug)
        {
            cout << "---- ---- ---- ---- done" << endl;
            cout << "PlateA : " << PlateAL << " | " << PlateAR << endl;
            cout << "PlateB : " << PlateB << endl;
            cout << "Count  : " << Counter << endl;
            cout << "PlateR : " << PlateR << endl;
            cout << "---- ---- ---- ---- ---- ---- ---- ---- DIVISION END" << endl;
        }



        return Number_CleanZeros(PlateR);
    }

    string Division_Safe (string InA, string InB, int InDecimalPrecesion)
    {
        string TempInA = InA;
        string TempInB = InB;

        //STEP1 : clean zeros
        TempInA = Number_CleanZeros(TempInA);
        TempInB = Number_CleanZeros(TempInB);
        
        //STEP2 : strip away negative sign
        TempInA = Number_GetAbs(InA);
        TempInB = Number_GetAbs(InB);
        string InAPosNeg = Number_IsPosIsNeg(InA);
        string InBPosNeg = Number_IsPosIsNeg(InB);

        //STEP3 : deal with decimal points
        while( Number_FracLength(TempInA,false) + Number_FracLength(TempInB,false) > 0)
        {
            TempInA = Multiplication_Safe(TempInA, Number_GetBase() );
            TempInB = Multiplication_Safe(TempInB, Number_GetBase() );
        }

        //STEP4 : arith
        string TempAnswer = Division(TempInA, TempInB, InDecimalPrecesion);

        //STEP5 : negative ?
        if (InAPosNeg == InBPosNeg)
        {
            return TempAnswer;
        }
        else
        {
            return CharracterNeg + TempAnswer;
        }
    }

    string Modulation (string InA, string InB)
    {
        // A mod B or A % B

        if (Number_GetAbs(InB) == "0")
        {
            cout << fowo.cOwOut.ConsoleQuick("error","division by 0") << endl;
            return ResultIfError;
        }

        if (Number_IsPosIsNeg(InB) == "-")
        {
            cout << fowo.cOwOut.ConsoleQuick("error","modular is negative") << endl;
            return ResultIfError;
        }
        else
        {
            string TempA = InA;
            string TempB = InB;

            while( Number_Compare(TempA,TempB) == "A>B" || Number_Compare(TempA,TempB) == "A=B" || Number_Compare(TempA,Charracter_Shorthand_Set_Zero()) == "A<B")
            {
                if (Number_Compare(TempA,TempB) == "A>B" || Number_Compare(TempA,TempB) == "A=B")
                {
                    TempA = Subtraction_Safe(TempA,TempB);
                }
                else if (Number_Compare(TempA,Charracter_Shorthand_Set_Zero()) == "A<B")
                {
                    TempA = Addition_Safe(TempA,TempB);
                }
            }

            return TempA;
        }
    }



    string Exponent_Int(string InBase, string InPow)
    {
        if
        (
            Number_FracLength(InPow, false) > 0 ||
            Number_IsPosIsNeg(InPow) == "-"
        )
        {
            cout << fowo.cOwOut.ConsoleQuick("error","power must be a positive integer") << endl;
            return ResultIfError;
        }

        string Plate_Box = Charracter_Shorthand_Set(1);
        string Plate_Pow = InPow;

        while( Number_Compare( Plate_Pow , Charracter_Shorthand_Set_Zero() ) == "A>B" )
        {
            Plate_Box = Multiplication_Safe(Plate_Box , InBase);
            Plate_Pow = Subtraction_Safe( Plate_Pow , Charracter_Shorthand_Set(1) );
            //cout << "Plate_Pow : " << Plate_Pow << endl;
        }

        return Plate_Box;
    }


};

/*

string TempA = "0";
string TempB = "5";
for(TempA = "-10" ; smowo.Number_Compare(TempA,"10") == "A<B" ; TempA = smowo.Addition_Safe(TempA,"1"))
{
    for(TempB = "-10" ; smowo.Number_Compare(TempB,"10") == "A<B" ; TempB = smowo.Addition_Safe(TempB,"1"))
    {
        cout << "TempA : " << TempA << " , TempB : " << TempB;
        cout << " , A+B : " << smowo.Addition_Safe(TempA,TempB);
        cout << " , A-B : " << smowo.Subtraction_Safe(TempA,TempB);
        cout << " , A*B : " << smowo.Multiplication_Safe(TempA,TempB);
        cout << " , A/B : " << smowo.Division_Safe(TempA,TempB,4);
        cout << " , A%B : " << smowo.Modulation(TempA,TempB),
        cout << endl; 
    }
}

*/

