#include<graphics.h>//ͼ�ο��ļ� 
#include<conio.h>//����̨�������������getch()����
#include<time.h> 
#include<string.h>
#include<stdio.h>
#include<stdlib.h>//�������ͷ�ļ�



/*-------------------------------------------����--------------------------------------------------*/

void menu();//��ʼ�˵�
void play();//��ʼ��Ϸ���� 
void ptop();//����ģʽ
void ptoc();//�˻�ģʽ 
void help();//��Ϸ����
int isvaild(int a,int b);//�ж������Ƿ�Խ��
int judge();//�ж��Ƿ���������
void shuanfen(int i1,int j1);//������������
void Al1();//����AI
void black1(int i,int j,int l1);//�������
void white1(int i,int j,int l2);//������֣���в����
void again(int x);//��Ϸ�ж� 
void end_up1();//����ʤ 
void end_up2();// ����ʤ 
void Al2();//ǿAL
int dfs(int i,int j,int deep);//ģ���ս

int a[17][17];//���̣�0����ո�1������ӣ�2������� 

int paly1=1,flag1=0,flag2=0,flag3=0;
int flag = 0;
int x,y;

void save();//���˴浵
void load();//���˴浵����
void load2();//�˻��浵
void save2();//�˻��浵����

void main()  
    {  
        initgraph(950, 650, SHOWCONSOLE);
        menu();
        getch();
    }

void menu()  //��ʼ�˵�
    {  
        IMAGE img;  
        setaspectratio(1, 1);
		loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\timg��ʼ.jpg", 950, 650, false);
		putimage(0, 0, &img, SRCPAINT); 
		MOUSEMSG m;
		while (true)  
        {  
            m = GetMouseMsg();  
            if (m.uMsg == WM_MOUSEMOVE && m.x >= 570 && m.x <= 870 && m.y >= 470 && m.y <= 520)  
            {  
				loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\timg��ʼ��Ϸ.jpg", 950, 650, false);
				putimage(0, 0, &img, SRCPAINT); 
      
            }
            if (m.uMsg == WM_LBUTTONDOWN && m.x >= 570 && m.x <= 870 && m.y >= 470 && m.y <= 520)//�ж��Ƿ����˿�ʼ��Ϸ
            {  
                  
                play();  
                break;  
            }
		}
}
void play(){  //��Ϸ��ʼ����Ϸģʽ��ѡ��
		cleardevice();
		IMAGE img; 
		loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\1528416976709��Ϸ����.jpg", 950, 650, false);
		putimage(0, 0, &img, SRCPAINT);
		for (int i = 190; i <= 750; i += 40)//��������
        {   
			setlinecolor(BLACK);
            line(i, 40, i, 600);  
            line(190, i-150, 750, i-150);  
        }  
		MOUSEMSG m;
		while(true){
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN && m.x >= 26 && m.x <= 116 && m.y >= 286 && m.y <= 316){
				ptop();//����ģʽ
				break;
			}
			else if(m.uMsg == WM_LBUTTONDOWN && m.x >= 26 && m.x <=116  && m.y >=332  && m.y <= 362){
				ptoc();//�˻�ģʽ
				break;
			}
			else if(m.uMsg == WM_LBUTTONDOWN && m.x >= 26 && m.x <= 116 && m.y >= 396 && m.y <= 426){
				help();//��Ϸ����
				break;
			}
			else if(m.uMsg == WM_LBUTTONDOWN && m.x >= 778 && m.x <=868 && m.y >= 390  && m.y <= 420){
				cleardevice();
				loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\�˳���Ϸ.jpg", 950, 650, false);
				putimage(0, 0, &img, SRCPAINT);
				break;//�˳���Ϸ
			}
		  }
}

char str1[5];
char str2[5];
int bushu1, bushu2,play1,win;
void ptop(){   //����ģʽ
		settextstyle(30, 30, "����");
        settextcolor(WHITE);
		HWND wnd=GetHWnd();
		if(MessageBox(wnd,_T("�Ƿ�ȷ������ģʽ"),_T("��Ϸ����"),MB_OKCANCEL|MB_ICONQUESTION)==IDOK){
		cleardevice();
		IMAGE img; 
		loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\1528416976709����.jpg", 950, 650, false);
		putimage(0, 0, &img, SRCPAINT);
		for (int w = 190; w<= 750; w+= 40)//��������
        {   
			setlinecolor(BLACK);
            line(w, 40, w, 600);  
            line(190, w-150, 750, w-150);  
        }  
	    bushu1=0;bushu2=0;
        memset(a, 0, sizeof(a));  
        int i = 0, j = 0;
		int quit = MessageBox(NULL, "�Ƿ��ȡ�浵", "DW", MB_YESNO | MB_SYSTEMMODAL);
            if (IDYES == quit){
				load();    
			}
			else{
			    play1 = 1;
			    win = 0;
			}
        MOUSEMSG msg;  
        while (win == 0)  
        {  
            msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN)  
            {  
				if(msg.x >= 778 && msg.x <=880 && msg.y >= 375  && msg.y <= 410){
				   int quit = MessageBox(NULL, "�Ƿ񴢴�浵", "��Ϸ����", MB_YESNO | MB_SYSTEMMODAL);
                       if (IDYES == quit){
				           save();    
					   }
					
					//setlinecolor(YELLOW);
                //rectangle(778, 375, 880, 410);
				cleardevice();
				loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\�˳���Ϸ2.jpg", 950, 650, false);
				putimage(0, 0, &img, SRCPAINT);
				}
                for (int lie = 190; lie <= 750; lie += 40)  
                {  
                    if (msg.x <= lie + 10 && msg.x >= lie - 10)  
                    {  
                        for (int hang = 40; hang <= 600; hang += 40)  
                        {  
							
                            if (msg.y <= hang + 10 && msg.y >= hang - 10)  
                            {  
                                if (play1 == 1 && a[hang / 40][(lie-150) / 40] == 0)  
                                {  
                                    setfillcolor(BLACK);  
                                    solidcircle(lie, hang, 12);  
                                    a[hang / 40][(lie-150) / 40] = 1;  
                                    play1 = 0;  
                                    bushu1++;  
                                    sprintf(str1, "%i", bushu1);  
                                    outtextxy(855, 180, str1); 
									
                                    //break;  
                                }  
								
                                if (play1 == 0 && a[hang / 40][(lie-150) / 40] == 0)  
                                {  
                                    setfillcolor(WHITE);  
                                    solidcircle(lie, hang, 12);  
                                    a[hang / 40][(lie-150) / 40] = 2;  
                                    play1 = 1;  
                                    bushu2++;  
                                    sprintf(str2, "%i", bushu2);  
                                    outtextxy(855, 225, str2);
                                   // break;  
                                }  
								save();
								break;
                            }
							
                        }  
                    }  
                }  
            }
			win=judge();
		} 
	again(win);
	
	}
		else
		play();
}



void ptoc(){   //�˻�ģʽ
	settextstyle(30, 30, "����");
    settextcolor(WHITE);
	bushu1 = 0;bushu2 = 0; paly1=0;
	srand((unsigned)time(NULL));
	memset(a,0,sizeof(a));   
	HWND wnd=GetHWnd();
	if(MessageBox(wnd,_T("�Ƿ�ȷ���˻�ģʽ"),_T("��Ϸ����"),MB_OKCANCEL|MB_ICONQUESTION)==IDOK){
	cleardevice();
	IMAGE img; 
	loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\1528416976709�˻�ģʽ.jpg", 950, 650, false);
	putimage(0, 0, &img, SRCPAINT);
	for (int w = 190; w<= 750; w+= 40)//��������
        {   
			setlinecolor(BLACK);
            line(w, 40, w, 600);  
            line(190, w-150, 750, w-150);  
        } 
	    /*setlinecolor(YELLOW);
        rectangle(20, 285, 110, 325);
		rectangle(20, 335, 110, 375);
		rectangle(8, 400, 125, 432);
		rectangle(775, 370, 868, 415); */
	MOUSEMSG msg; 
	while(true){     //��Ϸѡ��
	msg = GetMouseMsg();
	if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 20 && msg.x <= 110 && msg.y >= 285 && msg.y <= 325){
	
	int quit = MessageBox(NULL, "�Ƿ��ȡ�浵", "��Ϸ����", MB_YESNO | MB_SYSTEMMODAL);
        if (IDYES == quit){
				load2();    
		}
	    else{		   
	 
	    if(MessageBox(wnd,_T("�˻�ģʽ�����Ƿ��õ������£�"),_T("��Ϸ����"),MB_OKCANCEL|MB_ICONQUESTION)==IDOK){
		int i=rand()%6+6;//��6~11֮�䣬��һ���������Ϊ���������X����
		int j=rand()%6+6;//��6~11֮�䣬��һ���������Ϊ���������Y���� 
		a[i][j]=1;
		setfillcolor(BLACK);
		fillcircle(j*40+150, 40*i,12);
		bushu1++;  
        sprintf(str1, "%i", bushu1);  
        outtextxy(855, 180, str1);	
		play1=0;
		}
	}
	win=0;
	while (win == 0)   //������
        {
            win=judge();
			if(win!=0)
				break;
			if (play1 == 1)
            {
                Al2();
			}
			win=judge();
			if(win!=0)
				break;
			if(play1==0){
				msg = GetMouseMsg();
				if (msg.uMsg == WM_LBUTTONDOWN){
				if(msg.x >= 778 && msg.x <=868 && msg.y >= 390  && msg.y <= 420){
					int quit = MessageBox(NULL, "�Ƿ�洢�浵", "DW", MB_YESNO | MB_SYSTEMMODAL);
                    if (IDYES == quit){
				        save2();    
					}
					cleardevice();
					IMAGE img;
				loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\�˳���Ϸ2.jpg", 950, 650, false);
				putimage(0, 0, &img, SRCPAINT); 
				}
                for (int lie = 190; lie <= 750; lie += 40)
                {
                    if (msg.x <= lie + 10 && msg.x >= lie - 10)
                    {
                        for (int hang = 40; hang <= 600; hang += 40)
                        {
                            if (msg.y <= hang + 10 && msg.y >= hang - 10)
                            {
                                if (a[hang / 40 ][(lie-150) / 40 ] == 0)
                                {
                                    setfillcolor(WHITE);
                                    solidcircle(lie, hang, 12);
                                    a[hang / 40 ][(lie-150) / 40 ] = 2;
                                    play1 = 1;
                                    bushu2++;
                                    sprintf(str2, "%i", bushu2);
                                    outtextxy(855, 225, str2);
                                    break;
                                }
                            }
							
                        }
                    }
				}
            }
			}
        }
        again(win); 
		break; 
	}
	else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 20 && msg.x <= 110 && msg.y >= 335 && msg.y <= 375){
		int quit = MessageBox(NULL, "�Ƿ��ȡ�浵", "��Ϸ����", MB_YESNO | MB_SYSTEMMODAL);
        if (IDYES == quit){
				load2();    
		}
	    else{		   
	    HWND wnd=GetHWnd();
	    if(MessageBox(wnd,_T("�˻�ģʽ�����Ƿ��õ������£�"),_T("��Ϸ����"),MB_OKCANCEL|MB_ICONQUESTION)==IDOK){
		int i=rand()%6+6;//��6~11֮�䣬��һ���������Ϊ���������X����
		int j=rand()%6+6;//��6~11֮�䣬��һ���������Ϊ���������Y���� 
		a[i][j]=1;
		setfillcolor(BLACK);
		fillcircle(j*40+150, 40*i,12);
		bushu1++;  
        sprintf(str1, "%i", bushu1);  
        outtextxy(855, 180, str1);	
		play1=0;
		}
	}
	win=0;
	while (win == 0)  //���ذ�
        {
            win=judge();
			if(win!=0)
				break;
			if (play1 == 1)
            {
                Al1();
			}
			win=judge();
			if(win!=0)
				break;
			if(play1==0){
           msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONDOWN)
            {
				if(msg.x >= 778 && msg.x <=868 && msg.y >= 390  && msg.y <= 420){
					int quit = MessageBox(NULL, "�Ƿ�洢�浵", "DW", MB_YESNO | MB_SYSTEMMODAL);
                    if (IDYES == quit){
				        save2();    
					}
					cleardevice();
					IMAGE img;
				loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\�˳���Ϸ.jpg", 950, 650, false);
				putimage(0, 0, &img, SRCPAINT);
				}
                for (int lie = 190; lie <= 750; lie += 40)
                {
                    if (msg.x <= lie + 10 && msg.x >= lie - 10)
                    {
                        for (int hang = 40; hang <= 600; hang += 40)
                        {
                            if (msg.y <= hang + 10 && msg.y >= hang - 10)
                            {
                                if (a[hang / 40 ][(lie-150) / 40 ] == 0)
                                {
                                    setfillcolor(WHITE);
                                    solidcircle(lie, hang, 12);
                                    a[hang / 40 ][(lie-150) / 40 ] = 2;
                                    play1 = 1;
                                    bushu2++;
                                    sprintf(str2, "%i", bushu2);
                                    outtextxy(855, 225, str2);
                                    break;
                                }
                            }
							
                        }
                    }
                }
            }
			}
        }
        again(win);
		break;  
	} 
	else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 8 && msg.x <= 125 && msg.y >= 400 && msg.y <= 432){
	play();
	break;
}
	else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 775 && msg.x <=868 && msg.y >= 370  && msg.y <= 415){
		cleardevice();
		loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\�˳���Ϸ.jpg", 950, 650, false);
		putimage(0, 0, &img, SRCPAINT);
		break;
	}
	}
}
		else
		play();	
}

void help(){  //��Ϸ����
	cleardevice();
	IMAGE img; 
	loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\��Ϸ��������2.jpg", 950, 650, false);
	putimage(0, 0, &img, SRCPAINT);
	MOUSEMSG m;
	while(true){
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && m.x >= 350 && m.x <= 580 && m.y >= 510 && m.y <= 565){
		setlinecolor(BROWN);
        rectangle(350, 510, 580, 565);
		cleardevice();
		play();
		break;
		}
	}
}

int isvaild(int a,int b){//�ж������Ƿ�Խ��
		if(a>15||a<1){
		   return 0;
		}
		if(b>15||b<1){
		   return 0;
		}
	       return 1;
	}
	
int f1[11]={1,-1,-1,-1,0,1,1,1,0};
int f2[11]={1,-1,0,1,1,1,0,-1,-1};
	int judge(){                           //�ж��Ƿ���������
		 int i,j;
		 int c,d;
		 int count1[6];
		 int count2[6];
		 int k,l;
		 for(i=1;i<=15;i++){
			 for(j=1;j<=15;j++){
				 memset(count1,0,sizeof(count1));
				 memset(count2,0,sizeof(count2));
				 for(k=1;k<=8;k++){
					 if(a[i][j]==1){
						 c=i;d=j;
					     for(l=1;l<=4;l++){
							 c=i+l*f1[k];
							 d=j+l*f2[k];
							 if(isvaild(c,d)==1&&a[c][d]==1){
							    count1[k>4?k-4:k]++;
							 }
							 else
							    break; 
						 }
					 }
					 else if(a[i][j]==2){
						  c=i;d=j;
					      for(l=1;l<=4;l++){
							 c=i+l*f1[k];
							 d=j+l*f2[k];
							 if(isvaild(c,d)==1&&a[c][d]==2){
							    count2[k>4?k-4:k]++;
							 }
							 else
							    break;
						  }
					 }
				 }
				 for(l=1;l<=4;l++){
					 if(count1[l]+1>=5){
					    return 1;
					 }
					 if(count2[l]+1>=5){
					    return 2;
					 }
				 }
			 }
		 }
		     return 0;
	}

int e[17][17][4];
	int kong1[17][17][6];
	int kong2[17][17][6];
	long score[17][17][4];
	//int count1[6];
    //int count2[6];
	void shuanfen(int i1,int j1){//������������
	     int k,l,c,d;
		 //memset(count1,0,sizeof(count1));
         //memset(count2,0,sizeof(count2));
         int count1[6]={0},count2[6]={0};
         memset(e,0,sizeof(e));	
         memset(kong1,0,sizeof(kong1));
		 memset(kong2,0,sizeof(kong2));
			if(a[i1][j1]==0){
               for(k=1;k<=8;k++){
                      c=i1;d=j1;
                      for(l=1;l<=4;l++){
                          c=i1+l*f1[k];
                          d=j1+l*f2[k];
                          if(isvaild(c,d)==1&&a[c][d]==1){
                             count1[k>4?k-4:k]++;
                          }
                          if(isvaild(c,d)==1&&a[c][d]==0){
							  kong1[i1][j1][k>4?k-4:k]++;
							      break;
                          }
                          else if(isvaild(c,d)==1&&a[c][d]==2)
                                  break;
                      }
					  c=i1;d=j1;
                      for(l=1;l<=4;l++){
                          c=i1+l*f1[k];
                          d=j1+l*f2[k];
                          if(isvaild(c,d)==1&&a[c][d]==2){
                             count2[k>4?k-4:k]++;
                          }
                          if((isvaild(c,d)==1&&a[c][d]==0)||isvaild(c,d)==0){
							  kong2[i1][j1][k>4?k-4:k]++;
							      break;
                          }
                          else if(isvaild(c,d)==1&&a[c][d]==1)
                                  break;
                      }
               }
                              for(l=1;l<=4;l++){
								  
                                  e[i1][j1][1]=count1[l]+1;
                                  e[i1][j1][2]=count2[l]+1;
                                  black1(i1,j1,l);
                                  white1(i1,j1,l);
                              }
			}
	}
     
    void Al1(){//������AI
		 int i,j,k,i1,j1,max;
		 max=0;
		 i1=0;
		 j1=0;
		 memset(score,0,sizeof(score));
         for(i=1;i<=15;i++){
			 for(j=1;j<=15;j++){
                 shuanfen(i,j);
				 //printf("%5d/%5d  ",score[i][j][1],score[i][j][2]);
				 for(k=1;k<=2;k++){
					 if(a[i][j]==0&&score[i][j][k]>=max){
					    max=score[i][j][k];
						i1=i;
						j1=j;
					 }
				 }
			 }
			 //printf("\n");
		 }
             setfillcolor(BLACK);
             solidcircle(j1*40+150, 40*i1, 12);
             a[i1][j1] = 1;
             play1 = 0;
             bushu1++;
             sprintf(str1, "%i", bushu1);
			 settextstyle(30, 30, "����");
			 settextcolor(WHITE);
             outtextxy(855, 180, str1);
    }

    void black1(int i,int j,int l1){
         if(e[i][j][1]==1){
			   if(kong1[i][j][l1]==2)
                   score[i][j][1]+=10;
               else if(kong1[i][j][l1]==1)
                   score[i][j][1]+=1;
               else{
                   score[i][j][1]+=1;
			   }
         }
         else if(e[i][j][1]==2){
                    if(kong1[i][j][l1]==2)
                       score[i][j][1]+=100;
                    else if(kong1[i][j][l1]==1)
                       score[i][j][1]+=10;
                    else{
                       score[i][j][1]+=2;
                    }
         }
         else if(e[i][j][1]==3){
                    if(kong1[i][j][l1]==2)
                       score[i][j][1]+=1000;
                    else if(kong1[i][j][l1]==1)
                       score[i][j][1]+=100;
                    else{
                       score[i][j][1]+=3;
                 }
         }
         else if(e[i][j][1]==4){
                    if(kong1[i][j][l1]==2)
                       score[i][j][1]+=10000;
                    else if(kong1[i][j][l1]==1)
                       score[i][j][1]+=1000;
                    else{
                       score[i][j][1]+=4;
                    }
         }
         else{
              score[i][j][1]+=1000000;
         }
    }
   
	
	void Al2(){   //����ǿAl
		flag1=0;flag2=0;flag3=0;
		int max,i1,j1,i,j,k;
	       for(i=1;i<=15;i++){
			 for(j=1;j<=15;j++){
                 shuanfen(i,j);
			//	 printf("%5d/%5d  ",score[i][j][1],score[i][j][2]);
				 for(k=1;k<=2;k++){
					 if(a[i][j]==0&&score[i][j][k]>=max){
					    max=score[i][j][k];
						i1=i;
						j1=j;
					 }
				 }
			 }
			//   printf("\n");
		 }
		 x=i1;
		 y=j1;
		 for(i=1;i<=15;i++){
			 for(j=1;j<=15;j++){
				 if(a[i][j]==0){
				   flag1=0;flag2=0;flag3=0;
                   dfs(i,j,0);
				   if(flag1==1||flag2==1){
		              x=i,y=j;
				   }
				      i=16;j=16;
				 }
			 }
		 }
         setfillcolor(BLACK);
             solidcircle(y*40+150, 40*x, 12);
             a[x][y] = 1;
             play1 = 0;
             bushu1++;
             sprintf(str1, "%i", bushu1);
			 settextstyle(30, 30, "����");
			 settextcolor(WHITE);
             outtextxy(855, 180, str1);
	}
    
	

    int dfs(int i, int j,int deep){
		int i1,j1,x1=0,y1=0,k,max;
    
		if(paly1==1){
		   paly1=0;
		   a[i][j]=1;
		 }	
		else{
		   paly1=1;
		   a[i][j]=2;
		 }

        if(deep>10){
			flag3=1;
		    return 1;
		 }
		
		if(judge()==2){
			a[i][j]=0;
            flag2=1;
		    return 1;
		}
        	
		if(judge()==1){
		    flag1=1;
			a[i][j]=0;
			return 1;
		 }

		if(flag2==0&&flag1==1&&deep!=0){
		   return 1;
		}
        if(flag2==1&&flag1==0&&deep!=0){
		   return 1;
		}
		if(flag3==1){
		   return 1;
		}	
        for(i1=1;i1<=15;i1++){
			 for(j1=1;j1<=15;j1++){
                 shuanfen(i1,j1);
			//	printf("%5d/%5d  ",score[i][j][1],score[i][j][2]);
				 for(k=1;k<=2;k++){
					 if(a[i1][j1]==0&&score[i1][j1][k]>=max){
					    max=score[i1][j1][k];
						x=i1;
						y=j1;
					 }
				 }
			 }
			// printf("\n");
		 }
        dfs(i,j,deep+1);
		if(flag1==1||flag2==1){
		   x=i;
		   y=j;
		}
		 a[i][j]=0;	 
		 
		return 0;
	}


void white1(int i,int j,int l2){//��в����
         if(e[i][j][2]==1){
               if(kong2[i][j][l2]==2)
                  score[i][j][2]+=10;
               else if(kong2[i][j][l2]==1)
                  score[i][j][2]+=1;
               else{
                  score[i][j][2]+=1;
            }
         }
         else if(e[i][j][2]==2){
                    if(kong2[i][j][l2]==2)
                       score[i][j][2]+=100;
                    else if(kong2[i][j][l2]==1)
                       score[i][j][2]+=10;
                    else{
                       score[i][j][2]+=2;
                    }  
         }
         else if(e[i][j][2]==3){
                    if(kong2[i][j][l2]==2)
                       score[i][j][2]+=1000;
                    else if(kong2[i][j][l2]==1)
                       score[i][j][2]+=100;
                    else{
                        score[i][j][2]+=3;
                    }
         }
         else if(e[i][j][2]==4){
                    if(kong2[i][j][l2]==2)
                       score[i][j][2]+=10000;
                    else if(kong2[i][j][l2]==1)
                       score[i][j][2]+=800;
                    else{
                       score[i][j][2]+=4;
                    }
         }
         else{
              score[i][j][2]+=1000000;
         }
	}

/*void again(int index)
    {
	if (index == 1){
		cleardevice();  
        //Sleep(500);
        end_up1();
	}
	else{
		cleardevice();  
        //Sleep(500);
        end_up2();
	}
    }*/
	void again(int index)
    {
        settextstyle(30, 30, "����");
        settextcolor(WHITE);
        if (index == 1)
        {
            outtextxy(300, 605, "���ӻ�ʤ!");
        }
        else
        {
            outtextxy(300, 605, "���ӻ�ʤ!");
        }
        int quit = MessageBox(NULL, "�Ƿ������Ϸ", "DW", MB_YESNO | MB_SYSTEMMODAL);
        if (IDYES == quit)
        {
            cleardevice();
			memset(score,0,sizeof(score));
			memset(a,0,sizeof(a));
			memset(str1,'0',sizeof(str1));
			memset(str2,'0',sizeof(str2));
			memset(e,0,sizeof(e));
			memset(kong1,0,sizeof(kong1));
			memset(kong2,0,sizeof(kong2));
			//memset(count1,0,sizeof(count1));
			//memset(count2,0,sizeof(count2));
			bushu1=0;bushu2=0;
            play();
        }
        else
        {
            cleardevice();
            IMAGE img; 
			loadimage(&img, "C:\\Users\\DELL\\Desktop\\������\\�˳���Ϸ.jpg", 950, 650, false);
			putimage(0, 0, &img, SRCPAINT);
        }
    }

    
	
	/*void load(){
	     FILE*fp;
		 fread();
		 if((fp = fopen("memory.rec", "r")) == NULL){
             fprintf(stderr, "No Game Cache Here!\n");
             exit(2);
		 }
		 for(i=1; i<=15; i++){
			 for(j=1; j<=15; j++){
			     fread();
			 }
		 }
		    fread();
	}

	void save(){
	     FILE*fp;
		 if((mem = fopen("memory.rec","w+")) == NULL){
             fprintf(stderr,"Can't open memory.txt!\n");
             exit(1);
		 }
	     fread();
         for(i=1;i<=15;i++){
			 for(j=1;j<=15;j++){
			     a[i][j]=fread();
			 }
		 }
		     play1=fread();
             
         
	}*/

    void save()
	{
		FILE * fp;
		if((fp = fopen("memory.rec", "wb+")) == NULL)
		{
			printf("Can't save the game!\n");
            exit(0);
		}
		rewind(fp);
		int is_win = win;
		fwrite(&is_win, sizeof(int), 1, fp);
		printf(" %d \n", is_win);
		int is_play = play1;
		fwrite(&is_play, sizeof(int), 1, fp);
		for(int i = 1; i <= 15; i++)
		{
			for(int j = 1; j <= 15; j++)
			{
				int t = a[i][j];
				fwrite(&t, sizeof(int), 1, fp);
				//printf("%d ", t);
			}
		}
		fseek(fp, 8L, 0);
		for(int m = 1; m <= 15; m++)
		{
			for(int n = 1; n <= 15; n++)
			{
				int t;
				fread(&t, sizeof(int), 1, fp);
				printf(" %d ", t);
			}
			printf("\n");
		}
		fclose(fp);
	}	

	void load()
	{
		printf("load......\n");
		FILE * fp;
		if((fp = fopen("memory.rec", "rb")) == NULL)
		{
			printf("No Game Cache Here!\n");
			exit(0) ;
		}
		rewind(fp);
		int t1;
		fread(&t1, sizeof(int), 1, fp);printf("%d \n", t1);
		win = t1;
		printf("%d \n", win);
		fread(&t1, sizeof(int), 1, fp);
		play1 = t1;
		printf("%d \n", play1);
		fseek(fp, 8L, 0);
		bushu1 = 0;
		bushu2 = 0;
		for(int i = 1; i <= 15; i++)
		{
			for(int j = 1; j <= 15; j++)
			{
				fread(&t1, sizeof(int), 1, fp);
				a[i][j] = t1;
				//printf("%d ", t);
				if(t1 == 1)
				{
					setfillcolor(BLACK);                
					int lie = i*40;
					int hang = j*40 + 150; 
					solidcircle(hang, lie, 12);
					bushu1++;  
                    sprintf(str1, "%i", bushu1);  
                    outtextxy(855, 180, str1); 
				}
				else if(t1 == 2)
				{
					setfillcolor(WHITE);                
					int lie = i*40;
					int hang = j*40 + 150;
					solidcircle(hang, lie, 12);
					bushu2++; 
					sprintf(str2, "%i", bushu2);  
                    outtextxy(855, 225, str2);
				}
			}
			printf("\n");
		}
		fclose(fp);
	}
	
	void save2()
	{
		FILE * fp;
		if((fp = fopen("memory2.rec", "wb+")) == NULL)
		{
			printf("Can't save the game!\n");
            exit(0);
		}
		rewind(fp);	
		for(int i = 1; i <= 15; i++)
		{
			for(int j = 1; j <= 15; j++)
			{
				int t = a[i][j];
				fwrite(&t, sizeof(int), 1, fp);
				//printf("%d ", t);
			}
		}
		fseek(fp, 8L, 0);
		for(int m = 1; m <= 15; m++)
		{
			for(int n = 1; n <= 15; n++)
			{
				int t;
				fread(&t, sizeof(int), 1, fp);
				printf(" %d ", t);
			}
			printf("\n");
		}
		fclose(fp);
	}	


	void load2()
	{
		printf("load2......\n");
		FILE * fp;
		if((fp = fopen("memory2.rec", "rb")) == NULL)
		{
			printf("No Game Cache Here!\n");
			exit(0) ;
		}
		rewind(fp);
		int t1;
		bushu1 = 0;
		bushu2 = 0;
		for(int i = 1; i <= 15; i++)
		{
			for(int j = 1; j <= 15; j++)
			{
				fread(&t1, sizeof(int), 1, fp);
				a[i][j] = t1;
				//printf("%d ", t);
				if(t1 == 1)
				{
					setfillcolor(BLACK);                
					int lie = i*40;
					int hang = j*40 + 150; 
					solidcircle(hang, lie, 12);
					bushu1++;  
                    sprintf(str1, "%i", bushu1);  
                    outtextxy(855, 180, str1); 
				}
				else if(t1 == 2)
				{
					setfillcolor(WHITE);                
					int lie = i*40;
					int hang = j*40 + 150;
					solidcircle(hang, lie, 12);
					bushu2++; 
					sprintf(str2, "%i", bushu2);  
                    outtextxy(855, 225, str2);
				}
			}
			printf("\n");
		}
		fclose(fp);
	}


































































