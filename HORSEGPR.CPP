void stupid(cell CB[S][S])
 {
  int uu;                     // ��६����� ��� �ࠢ����� ��室�� �� ESC;
  do{
  metodGPR(CB);
		textattr(0x1A);  	clrscr();
     gotoxy(30,15); cout<<"��� ��室� ������ Esc..."; // �뢮� ᮮ�饭�� �� ��࠭;
     uu = getch();
    }while(uu!=27);                              		   // ��室 �� Esc;

 }
//-------------------------------------------------------------------------
void metodGPR(cell CB[S][S])
{
  int step = 0;        			         // ��� � �����⬥ ��室�;
  cho=0;           			      // ������⢮ ᤥ����� 室��;
  brk=1;            			   // ��⠭���� ����প� � �������;
  regSTR=reg=0;                               // ����� ��筮�� �롮� 室�;
  VIZ=1;
   Viz(CB);
   zeroing(CB,step,cho);       			   // ��⠫쭮�� ���㫥���;
   Viz(CB);                                // ���㠫����� �嬠⭮�� ����;
   coordViz();                                 	    // �롮� �窨 �����;
  for(;;) {
	 switch (step){
	     case  0:  CB[i][j]=1; 		     // ��⠭���� � �������;
		       sign=-sign;  		// ����� ���ࠢ����� ��室�;
		       core *Way;
		       Way=CB[i][j].adrs(); // ���⨥ ���� ⥪. �������;
		       Way->n=cho;    // ���������� ���浪����� ����� 室�;
					step=1; continue;//���室 � case:1;
	     case  1:  Viz(CB);                            // �뢮� ������;
		       Progress(11,50,64,cho);  // �뢮� �ண��� ����樨;
					step=2; continue;
	     case  2:  step = assay(CB);  	continue;//�஢�ઠ �믮������;
	     case  3:  step = choSTP(CB); 	continue;//�롮� ᫥���饣�;
	     case  4:  backSTP(CB);
		       step = backSTP(CB);  continue; //�⪠� �� �㯨��;
	     case 10:  Stop(0);			return;//����砭�� ����樨;

	      default:                 step=10; continue; // ����砭�� ��
		   }                                             // ��䮫��;
	}
}
//------------------------ �롮� ᫥���饩 ����樨 --------------------------

int choSTP(cell CB[S][S])
 {

  core *Way;	Way=CB[i][j].adrs();   	  // ���� �祩�� ⥪�饣� ���������;

  int im=i, jm=j;            		       // ���� �����⨬��� ���室�.
  if(!(scanalon(CB,im,jm)))
   {
    Way->f++;
    int cs=Way->f;
    switch(cs){
	      case 1:
    if((i>1)&&(j<7)&&(!CB[i-2][j+1].cors()))
       {
	im=i-2; jm=j+1;		break;
       }
					   // �࠭���� �ਮ��⭮� ����樨;
	      case 2:
    if((i>0)&&(j<6)&&(!CB[i-1][j+2].cors()))
       {
	im=i-1; jm=j+2;		break;
       }
					   // �࠭���� �ਮ��⭮� ����樨;
	      case 3:
    if((i<7)&&(j<6)&&(!CB[i+1][j+2].cors()))
       {
	im=i+1; jm=j+2;		break;
       }
					   // �࠭���� �ਮ��⭮� ����樨;
	      case 4:
    if((i<6)&&(j<7)&&(!CB[i+2][j+1].cors()))
       {
	im=i+2; jm=j+1;		break;
       }
					   // �࠭���� �ਮ��⭮� ����樨;
	      case 5:
    if((i<6)&&(j>0)&&(!CB[i+2][j-1].cors()))
       {
	im=i+2; jm=j-1;		break;
       }
					   // �࠭���� �ਮ��⭮� ����樨;
	      case 6:
    if((i<7)&&(j>1)&&(!CB[i+1][j-2].cors()))
       {
	im=i+1; jm=j-2;		break;
       }
					   // �࠭���� �ਮ��⭮� ����樨;
	      case 7:
    if((i>0)&&(j>1)&&(!CB[i-1][j-2].cors()))
       {
	im=i-1; jm=j-2;		break;
       }
					   // �࠭���� �ਮ��⭮� ����樨;
	      case 8:
    if((i>1)&&(j>0)&&(!CB[i-2][j-1].cors()))
       {
	im=i-2; jm=j-1;		break;
       }
					   // �࠭���� �ਮ��⭮� ����樨;
	      default: 		 //	clrscr();     // �᫨ ����� � �㯨�!
//    gotoxy(30,10); printf("%s", "������ ����㤨����...");cout<<Way->f;	delay(1000);
    Viz(CB);
    Way->f=0;
    return 4;				    // ��室 �� ᫥����騩 蠣;
    }
   }
  if(regSTR)              // ��⮬���᪨� ०�� ���室� �� �ਮ���� 室;
  {
   CB[im][jm].change(i,j,0);                    // ���࠭���� ���� �।��;
   i=(abc)im;  				    // ��७����祭�� �窨 �����.
   j=(abc)jm;
   gotoxy(59+2*j,13-i);					delay(10);
  }
  else   parsing(CB);    		  // ��筮� ०�� �롮� ��६�����;
		       cho++;                   // ���६��� ���稪� 室��;
  return 0;                                      // ��室 �� ᫥����騩 蠣;

}
//------------------------ ���� �����筮 ���室� --------------------------
int scanalon(cell CB[S][S], int &im, int &jm)
{
   int key=0;                  	  // ���� ����� ���� �����⨬��� ���室�.

 if((i>1)&&(j<7)&&(!CB[i-2][j+1].cors())) { storSTP(CB,im,jm,key,i-2,j+1); }
 if((i>0)&&(j<6)&&(!CB[i-1][j+2].cors())) { storSTP(CB,im,jm,key,i-1,j+2); }
 if((i<7)&&(j<6)&&(!CB[i+1][j+2].cors())) { storSTP(CB,im,jm,key,i+1,j+2); }
 if((i<6)&&(j<7)&&(!CB[i+2][j+1].cors())) { storSTP(CB,im,jm,key,i+2,j+1); }
 if((i<6)&&(j>0)&&(!CB[i+2][j-1].cors())) { storSTP(CB,im,jm,key,i+2,j-1); }
 if((i<7)&&(j>1)&&(!CB[i+1][j-2].cors())) { storSTP(CB,im,jm,key,i+1,j-2); }
 if((i>0)&&(j>1)&&(!CB[i-1][j-2].cors())) { storSTP(CB,im,jm,key,i-1,j-2); }
 if((i>1)&&(j>0)&&(!CB[i-2][j-1].cors())) { storSTP(CB,im,jm,key,i-2,j-1); }

 if(key)
  {
   if(!regSTR)
    {	gotoxy(jm*7+15,(7-im)*5+7); cout << "���";
	gotoxy(jm*7+14,(7-im)*5+9); cout << "����!";
    }
   return 1;
  }
 else		return 0;
}
//--------------------- �࠭���� �ਮ��⭮� ����樨 -----------------------

void storSTP(cell CB[S][S],int &im, int &jm,  int &key, int id, int jd)
 {
  int temp=8;     			     // ������ �����⨬�� ���室��;
  if((id>1)&&(jd<7)) temp-=CB[id-2][jd+1].cors();	else temp--;
  if((id>0)&&(jd<6)) temp-=CB[id-1][jd+2].cors();	else temp--;
  if((id<7)&&(jd<6)) temp-=CB[id+1][jd+2].cors();	else temp--;
  if((id<6)&&(jd<7)) temp-=CB[id+2][jd+1].cors();	else temp--;
  if((id<6)&&(jd>0)) temp-=CB[id+2][jd-1].cors();	else temp--;
  if((id<7)&&(jd>1)) temp-=CB[id+1][jd-2].cors();	else temp--;
  if((id>0)&&(jd>1)) temp-=CB[id-1][jd-2].cors();	else temp--;
  if((id>1)&&(jd>0)) temp-=CB[id-2][jd-1].cors();	else temp--;
 Pr_Zw(jd*7+12,(7-id)*5+5,7,5,0xf,0xC,0);
/* if(temp<2)            // �����㦥��� ����襣� ���-�� �����⨬�� ���室��;
   {im=id; jm=jd; key=1;}   // �࠭���� ���� ����樨 � 䨪��� १����;
*/ if((id==0&&jd==0)||(id==0&&jd==7)||(id==7&&jd==0)||(id==7&&jd==7))
  {im=id; jm=jd; key=1;}   // �࠭���� ���� ����樨 � 䨪��� १����;
 }

//------------------------- ������ � ࠧ����� ------------------------------
int backSTP(cell CB[S][S])
 {
  core *Way; Way=CB[i][j].adrs();       // ���⨥ ���� ⥪��饣� ���������;
  cho--;                                 // �⪠� ������⢠ �ன����� 蠣��;
  Way->z=0; 				      // ���㫥��� ⥪�饣� ���祭��;
  Viz(CB); gotoxy(32,2); cout<< "�⪠� ���������...";
  Progress(11,50,64,cho);         //                      	 delay(1000);
  i=(abc)Way->i;                          // ���室 � �।��饩 ����樨;
  j=(abc)Way->j;
  return 0;
 }

//----------------------- �஢�ઠ �� �뫥� �� ���� -------------------------
int prover(int id, int jd)
 {
  if(id<0 || id>7 || jd<0 || jd>7) return 0;
  else return 1;
 }


//***************************************************************************
