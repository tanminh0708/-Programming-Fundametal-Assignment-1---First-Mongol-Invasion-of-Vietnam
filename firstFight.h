/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2021
    * Author: Nguyen Thanh Nhan
    * Date: 08.02.2021
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef firstFight_h
#define firstFight_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
int getReady(int& HP, const int& ID, int& M, const int& E1){
    int h,j,x;
    // Truong hop 1  
    if (E1 >=100 && E1 <= 500) { 
    if (E1 >= 100 && E1 <= 199)
    {
        // --------------------------- // cai dat lai 
        if (HP > 1000) HP = 1000;
            else if (HP < 0) HP = 0;
        if (M > 1000) M = 1000;
            else if (M < 0) M = 0;
            // --------------------------- // cai dat lai 
    h = (E1-100) % 64; // do cao treo mon do thu thach
    j = HP % 100; // kha nang nhay cao cua binh linh, j> h thi mua do [ma van dap ung dc dk mon do do], ko thi khoi
        if (j > h && ID == 0) // ID = 0 => TEAM KY BINH MUA DO KHONG CO VUA TRAN VA TONG CHI HUY 
        {
                if (M >= 300 && M % 2 == 1 && HP >= 500) 
                { 
                    M -= 300;
                    HP += 50;
                            } // Tien lon hon 300 , la so le va mau tren 500
                if (M >= 200 &&  M % 2 == 0 ) 
                {
                    M-=200;
                      HP+=25;
                        }// Tien lon hon 200 , la so chan.
        }
if (ID == 1) HP += 75; // team vua tran , dc mua het ma khong can tra tien 
// team ngot luong hop thai, chu quan nen khong mua trang bi
// --------------------------- // re-check
        if (HP > 1000) HP = 1000;
            else if (HP < 0) HP = 0;
        if (M > 1000) M = 1000;
            else if (M < 0) M = 0;
            // --------------------------- // re-check
         } // end truong hop 1 --> Check 1 

 if (E1 >= 200 && E1 <= 299) // truong hop 2 
    {  
       // --------------------------- // cai dat lai 
        if (HP > 1000) HP = 1000;
            else if (HP < 0) HP = 0;
        if (M > 1000) M = 1000;
            else if (M < 0) M = 0;
            // --------------------------- // cai dat lai 
                    x = E1 % 4 + 1; // chi so xac dinh mon do can mua 
         if (M % 2 == 1 && ID == 0) // Team k phai vua tran & NLHT mua do, so tien la le thi moi duoc mua do co gia tien la so chan 
        {
             // Ma so mon do le --> Gia mon do chan. 
                if ( x == 1 && M >= 190) 
                {
                    HP += 5;
                    M -= 190;
                }
                 if ( x == 3 && M >=200 ) 
                {
                    HP += 9;
                    M -= 200;
                }
            
        } // end case M le, Mua do co gia tien chan 
        else if (M % 2 == 0 && ID == 0) // Team k phai vua tran & NLHT mua do, so tien la chan thi moi duoc mua do co x la so le
           { // Ma so mon do chan --> Gia mon do le. 
                if ( x == 2 && M >= 195 ) 
                {
                    HP += 7;
                    M -= 195;
                }
                 if ( x == 4 && M >= 205) 
                {
                    HP += 11;
                    M -= 205;
                }
            
        }
            else if (ID != 0) // nha vua Tran + tong chi huy NLHT mua do. 
            {
                 if ( x == 1 && M >= 190 ) 
                {
                    HP += 5;
                    M -= 190;
                }
                else if ( x == 2 && M >= 195 ) 
                {
                    HP += 7;
                    M-=195;
                }
                else if ( x == 3 && M >= 200  ) 
                {
                    HP += 9;
                    M -= 200;
                }
                else if ( x == 4 && M >=205 ) 
                {
                    HP += 11;
                    M-=205;
                }
            } // end NLHT & Vua Tran
           // --------------------------- // re-check
        if (HP > 1000) HP = 1000;
            else if (HP < 0) HP = 0;
        if (M > 1000) M = 1000;
            else if (M < 0) M = 0;
            // --------------------------- // re-check

        } // end truong hop 2 --> OK 
    else if (E1 >= 300 && E1 <= 399) // Truong hop 3
    {
        // --------------------------- // cai dat lai 
        if (HP > 1000) HP = 1000;
            else if (HP < 0) HP = 0;
        if (M > 1000) M = 1000;
            else if (M < 0) M = 0;
            // --------------------------- // cai dat lai 
     if (HP >= 600 && ( (HP % 10) == 2 || (HP % 10) == 3 || (HP % 10) == 5 || (HP % 10) == 7 ) )
     {
             if (M >= 500)
             {
                if (ID != 1)
                        {
                            if ((E1 % 10) == 2 || (E1 % 10) == 3 || (E1 % 10) == 5 || (E1 % 10) == 7 ) HP += ceilf (HP*2.0*2*(E1 % 10)/100);
                                else HP += ceilf(HP*2.0*0.01);
                            M -= 500;
                            // --------------------------- // re-check
                                if (HP > 1000) HP = 1000;
                                    else if (HP < 0) HP = 0;
                                if (M > 1000) M = 1000;
                                    else if (M < 0) M = 0;
                             // --------------------------- // re-check
                        }
            else 
                {
                HP += 200;
                M -= 500;
                if (HP > 1000) HP = 1000;
                         // --------------------------- // re-check
                        if (HP > 1000) HP = 1000;
                            else if (HP < 0) HP = 0;
                        if (M > 1000) M = 1000;
                            else if (M < 0) M = 0;
                        // --------------------------- // re-check
                }
             }
             else {
                  // --------------------------- // re-check
        if (HP > 1000) HP = 1000;
            else if (HP < 0) HP = 0;
        if (M > 1000) M = 1000;
            else if (M < 0) M = 0;
            // --------------------------- // re-check
             }
         }
        else if (HP >= 600 && ( (HP % 10) != 2 || (HP % 10) != 3 || (HP % 10) != 5 || (HP % 10) != 7 ) )
        {
            if (M >=300)
            {
            if ((E1 % 10) == 2 || (E1 % 10) == 3 || (E1 % 10) == 5 || (E1 % 10) == 7 ) HP += ceilf (HP*2.0*(E1 % 10)/100);
            else HP += ceilf (HP*0.01);
            M -= 300;
             // --------------------------- // re-check
        if (HP > 1000) HP = 1000;
            else if (HP < 0) HP = 0;
        if (M > 1000) M = 1000;
            else if (M < 0) M = 0;
            // --------------------------- // re-check
            }
            else 
            {
                 // --------------------------- // re-check
        if (HP > 1000) HP = 1000;
            else if (HP < 0) HP = 0;
        if (M > 1000) M = 1000;
            else if (M < 0) M = 0;
            // --------------------------- // re-check
            }
        }
    } // end truong hop 3 
        else if (E1 >= 400 && E1 <= 499) // truong hop 4
        {
            // --------------------------- // cai dat lai 
        if (HP > 1000) HP = 1000;
            else if (HP < 0) HP = 0;
        if (M > 1000) M = 1000;
            else if (M < 0) M = 0;
            // --------------------------- // cai dat lai 
            if (E1 % 5 == 0) HP = ceilf (HP*0.9);
        } // end truong hop 4
          else if (E1 == 500)  // truong hop 5
        {
            // --------------------------- // cai dat lai 
        if (HP > 1000) HP = 1000;
            else if (HP < 0) HP = 0;
        if (M > 1000) M = 1000;
            else if (M < 0) M = 0;
            // --------------------------- // cai dat lai 
            M = ceilf (M*0.75);
            HP = ceilf (HP*0.75);
        } // end truong hop 5            
return (HP+M); 
    }
    else return -999;
    }
int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){  
    int r = 0;
    if (E2 >= 100 && E2 <= 199) // truong hop 1 : Mong co chu dong tan cong ; Quan nha Tran uu the dia hinh 
    {
        int u; 
        HP1 =       ceilf(HP1*1.1); // nha tran dc cong them 10% mau
        HP2 =       ceilf (HP2*1.3) ; // Mong co dc cong them 30% 
        // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 > 1000) HP1 = 1000;
            else if (HP1 < 0) HP1 = 0;
         if (HP2 > 1000) HP2 = 1000;
            else if (HP2 < 0) HP2 = 0;
// -------------------------------------------------------------------///
        if (ID1 == 1 && ID2 == 2) r = 0;
        else if ( ID1 == 1 && ID2 == 0 ) 
        {
            HP2 = 0; 
            r = 1;
        }
        else if ( ID1 == 0 && ID2 == 2 )  
        {
            HP1 = 0;
            r = -1;
        }
        // -------special case --------------- /
            else {
        u   =       ceilf((2.0*HP1*HP2)/(HP1+HP2)); //  chi so chien dau
        int temp = HP1; 
        HP1 =       HP1 - abs(ceilf(HP2 - u));
        HP2 =       HP2 - abs(ceilf(temp - u));
           // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 < 0) HP1 = 0;
        if (HP2 < 0) HP2 = 0;
// -------------------------------------------------------------------///
        if (HP1 > HP2) r = 1;
        else if (HP1 < HP2) r = -1;
        else if (HP1 == HP2) r = 0;
    }
        HP1 = ceilf (HP1*0.8);
} // end truong hop 1 
    else  if (E2 >= 200 && E2 <= 299) // truong hop 2 : Nha Tran chu dong, quan Mong co co su chuan bi
    {int u; 
        HP1 =      ceilf (HP1*1.7); // Nha Tran tang 70 % mau
        HP2 =      ceilf (HP2*1.2); // Mong Co tang 20% mau
             // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 > 1000) HP1 = 1000;
            else if (HP1 < 0) HP1 = 0;
         if (HP2 > 1000) HP2 = 1000;
            else if (HP2 < 0) HP2 = 0;
// -------------------------------------------------------------------///
        // -------special case --------------- //
        if (ID1 == 1 && ID2 == 2) r =  0;
        else if ( ID1 == 1 && ID2 == 0 ) 
        {
            HP2 = 0; 
            r = 1;
        }
        else if ( ID1 == 0 && ID2 == 2 )  {
            HP1 = 0;
            r= -1;
        }
        else 
        {
        u   =       ceilf((2.0*HP1*HP2)/(HP1+HP2)); //  chi so chien dau
        int temp = HP1; 
        HP1 =       HP1 - abs(ceilf(HP2 - u));
        HP2 =       HP2 - abs(ceilf(temp - u));
         // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 < 0) HP1 = 0;
        if (HP2 < 0) HP2 = 0;
// -------------------------------------------------------------------///
        if (HP1 > HP2) r = 1;
        else if (HP1 < HP2) r = -1;
        else if (HP1 == HP2) r = 0;
        }
    HP1 = ceilf (HP1*0.8);
    } // end TH 2 
      else if (E2 >= 300 && E2 <= 399) // TH3 quan ta (nha Tran) duoc trang bi day du vu khi va dung cu chien dau. 
    {int u; 
       
        if (E2 >= 350) HP1 += E2 % 100; // mau tren hoac bang 350 
                        else HP1 += 30; // duoi hoan toan 350
                            // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 > 1000) HP1 = 1000;
            else if (HP1 < 0) HP1 = 0;
         if (HP2 > 1000) HP2 = 1000;
            else if (HP2 < 0) HP2 = 0;
// -------------------------------------------------------------------///
if (ID1 == 1 && ID2 == 2) r= 0;
        else if ( ID1 == 1 && ID2 == 0 ) 
        {
            HP2 = 0; 
            r=1;
        }
        else if ( ID1 == 0 && ID2 == 2 )  {
            HP1 = 0;
            r=-1;
        }
       else {  
        u   =       ceilf( (2.0*HP1*HP2) / (HP1+HP2) ); //  chi so chien dau
      int temp = HP1; 
        HP1 =       HP1 - abs(ceilf(HP2 - u));
        HP2 =       HP2 - abs(ceilf(temp - u));
      // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 < 0) HP1 = 0;
        if (HP2 < 0) HP2 = 0;
// -------------------------------------------------------------------///
        if (HP1 > HP2) r = 1;
        else if (HP1 < HP2) r = -1;
        else if (HP1 == HP2) r = 0;
       }
    HP1 = ceilf (HP1*0.8);
    } // end TH3 
     else if (E2 >= 400 && E2 <= 499) // TH4 Ra quan voi tuong Binh HP quan Tran tang 30%, quan dich giam y chi, mau giam 20%. 
     // Tuy nhien, con trai tuong quan ha lenh bat mu` mat tuong binh, HP quan ta giam di mot nu?a 
    {
        int u; 
        HP1= ceilf (HP1*1.3);
        if (HP1 > 1000) HP1 = 1000;
        HP1= ceilf (HP1*0.5);
        HP2 = ceilf (HP2*0.8);
            // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 > 1000) HP1 = 1000;
            else if (HP1 < 0) HP1 = 0;
         if (HP2 > 1000) HP2 = 1000;
            else if (HP2 < 0) HP2 = 0;
// -------------------------------------------------------------------///
       if (ID1 == 1 && ID2 == 2) r = 0;
        else if ( ID1 == 1 && ID2 == 0 ) 
        {
            HP2 = 0; 
            r= 1;
        }
        else if ( ID1 == 0 && ID2 == 2 )  {
            HP1 = 0;
            r= -1;
        } 
     else { 
        u   =       ceilf((2.0*HP1*HP2)/(HP1+HP2)); //  chi so chien dau
       int temp = HP1; 
        HP1 =       HP1 - abs(ceilf(HP2 - u));
        HP2 =       HP2 - abs(ceilf(temp - u));
     // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 < 0) HP1 = 0;
        if (HP2 < 0) HP2 = 0;
// -------------------------------------------------------------------///
        if (HP1 > HP2) r = 1;
        else if (HP1 < HP2) r = -1;
        else if (HP1 == HP2) r = 0;
    } // end TH4 
    HP1 = ceilf (HP1*0.8);
    }
     // luon xay ra khi 4 TH dau tien ket thuc . Rut quan. HP quan Tran giam 20 % , ke ca do nha vua chi huy  
    if (E2 >= 500 || E2 < 100) return -999;
    if (r==1) return 1;
    if (r==0) return 0;
    return -1; 
}
int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
     int r = 0;
   if (E3 >= 100 && E3 <= 199) // start case 1 
    {
        HP1 = ceilf (HP1*1.4); 
         HP2 = ceilf (HP2*1.6);
             // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 > 1000) HP1 = 1000;           
         if (HP2 > 1000) HP2 = 1000;
// -------------------------------------------------------------------///
        if (ID2 != 2) HP2 = ceilf (HP2* 0.95); // Không co chi huy, HP Mong Co giam 5 %
    if (ID1 == 1) HP1 *= 2; // VUA  Tran Chi huy, hp tang gap doi .
       // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 > 1000) HP1 = 1000;           
         if (HP2 > 1000) HP2 = 1000;
// -------------------------------------------------------------------///
    int u;
        if (ID1 == 1 && ID2 == 2) r= 0;
        else if ( ID1 == 1 && ID2 == 0 ) 
        {
            HP2 = 0; 
            r= 1;
        }
        else if ( ID1 == 0 && ID2 == 2 )  r= -1;
        else {
            // *Tam thoi* full mau goc cho quan ta 
        u   =       ceilf((2.0*HP1*HP2)/(HP1+HP2)); //  chi so chien dau
       int temp = HP1; 
        HP1 =       HP1 - abs(ceilf(HP2 - u));
        HP2 =       HP2 - abs(ceilf(temp - u));
         // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 < 0) HP1 = 0;
        if (HP2 < 0) HP2 = 0;
// -------------------------------------------------------------------///
        if (HP1 > HP2) r = 1;
        else if (HP1 < HP2) 
        {
            HP1 = temp;
            r = -1;
        }
        else if (HP1 == HP2) r = 0;
        }
    } // end case 1 
    else  if (E3 >= 200 && E3 <= 299) // start case 2 
    {      
        HP1 = ceilf (HP1*1.4); 
         HP2 = ceilf (HP2*1.6);
            // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 > 1000) HP1 = 1000;           
         if (HP2 > 1000) HP2 = 1000;
// -------------------------------------------------------------------///
    if (ID1 == 1) HP1 *= 2; // VUA  Tran Chi huy, hp tang gap doi .
    if (ID2 != 2) HP2 = ceilf (HP2*0.95) ; // giong case 1 luc na~y
       // --------Check lai gia tri sau tinh toan ------------------///
        if (HP1 > 1000) HP1 = 1000;           
         if (HP2 > 1000) HP2 = 1000;
// -------------------------------------------------------------------///
    r = 0;
    } // end case 2 
    if (E3 > 299 || E3 < 100) return -999;
    if (r==1) return 1;
    if (r==0) return 0;
    return -1; 
}
//Quan ta phan cong // done 
int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
    int r = 0;
   if (E4 >= 100 && E4 <= 199) // start case 1: Vuon khong nha trong
    {
       if (ID2 != 2) HP2 = ceilf (HP2 * 0.1); 
            else if (ID2 == 2) HP2 = ceilf (HP2 * 0.3); // Ung vs 2 TH: Khong co tong chi huy va nguoc lai. 
        r= 0;
    }
     // end case 1 
     else if (E4 >= 200 && E4 <= 299) // start case 2 : Phan cong
    {
      HP2 = 0;
      r= 1;
    } // end case 2 
    if (E4 > 299 || E4 < 100) return -999; 
        if (r==1) return 1;
            if (r==0) return 0;
                         return -1; 
}
// int getReady(int& HP, const int& ID, int& M, const int& E1){
//     //Complete this function to gain point on task 1
//     return -1;
// }

// int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){
//     //Complete this function to gain point on task 2
//     return -1;
// }

// int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
//     //Complete this function to gain point on task 3
//     return -1;
// }

// int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
//     //Complete this function to gain point on task 4
//     return -1;
// }
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* firstFight_h */