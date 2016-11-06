 //    KEHITETTŽVŽŽ:
 //
 //  1 peli,asetukset,2 peli valikot,per„ luisut,t”rm„ys,tallentaminen,musiikki,„„net,

 #include <stdio.h>
 #include <allegro.h>
 #include <conio.h>

  typedef struct
  {
  int x_min, x_max, y_min, y_max;
  } ESTE;
 
  int main(void)
  {

        BITMAP *tausta;      // kentt„ joka vaihtuu joksikin alla olevista...
                       // semmoinen iso kuva jonka p„„lle piirret„„n
        BITMAP *nurmi;
        BITMAP *kasi;

        BITMAP *car;         //alkukuva

        BITMAP *pl1;          //pelaajat
        BITMAP *pl2;

        BITMAP *hilux;        // koneitten/autojen  kuvia
        BITMAP *corolla;
        BITMAP *poliisi;
        BITMAP *porsche;
        BITMAP *Lada;
        BITMAP *Fighter;
        BITMAP *Ensivaste;
        BITMAP *SPR_Mobile;
        BITMAP *Jeeppi;
        BITMAP *Fiat;
        
        BITMAP *tummaa;  //per„luikasta tumman harmaata vanaa

        BITMAP *kivi;          //esteit„

        BITMAP *pl1_taus;    // kuvien taustoja
        BITMAP *pl2_taus;

        PALETTE pal;          // Paletti nimelt„ "pal"

        ESTE kivet[5] = {{57, 70, 39, 70},
                         {53, 71, 56, 71},
                         {71, 72, 33, 72},
                         {53, 73, 70, 73},
                         {53, 74, 90, 74}};

        int scp_1_x_min=10;
        int scp_1_x_max=60;           //tarkistuspisteit„ pl1
        int scp_1_y_min=110;
        int scp_1_y_max=160;
        int scp_2_x_min=10;
        int scp_2_x_max=60;           //tarkistuspisteit„ pl2
        int scp_2_y_min=110;
        int scp_2_y_max=160;
        int scp1_x_min=10;
        int scp1_x_max=60;         //1. piste
        int scp1_y_min=110;
        int scp1_y_max=160;
        int scp2_x_min=10;
        int scp2_x_max=60;         //2. piste
        int scp2_y_min=1;
        int scp2_y_max=50;
        int scp3_x_min=130;         //3. piste
        int scp3_x_max=180;
        int scp3_y_min=40;
        int scp3_y_max=100;
        int scp4_x_min=250;          //4. piste
        int scp4_x_max=300;
        int scp4_y_min=1;
        int scp4_y_max=50;
        int scp5_x_min=130;
        int scp5_x_max=145;        //5. piste
        int scp5_y_min=110;
        int scp5_y_max=170;
        int looppi=700000;
        int pl1_x=81;             // koneen x-akseli
        int pl2_x=70;
        int pl1_y=50;             // koneen y-akseli
        int pl2_y=10;
        float nopeus=0.05;
        float pl1_nopeus_y=0;
        float pl2_nopeus_y=0;
        float pl1_nopeus_x=0;
        float pl2_nopeus_x=0;
        float x=150;     //1. pelaajan x-koordinaatti
        float px=0;      //per„luisun x-koordinaatti
        float x2=153;    //2. pelaajan x-koordinaatti
        float y=115;     //1. pelaajan y-koordinaatti
        float py=0;      //per„luisun y-koordinaatti
        float y2=133;    //2. pelaajan y-koordinaatti
        int pl1_asento=14;
        int pl2_asento=14;
        int rata=1;
        int valikko_1pl=1;
        int asetukset_valikko=1;
        int nimi_1pl_valikko=1;
        int nimi_2pl_valikko=2;
        int nimi_1pl_luku=1;
        int nimi_2pl_luku=2;
        int luku=0;
        int asetukset_luku=0;
        float vetovoima=0;
        long double a=0;
        int loppu=0;
        int ohjaus=5;
        int scp_pl1=0;
        int scp_pl2=0;
        int kierros_pl1=0;
        int kierros_pl2=0;
        int pl1_s_osa=0;
        int pl2_s_osa=0;
        int pl1_s=0;
        int pl2_s=0;
        int lopetetaanko=-5;
        int info=6;
        int vana=0;
        int turha=0;
        int versio=6;
        int moninpl=6;
        int enkka=6;
        int teksti=0;
        int rata1_s=0, rata2_s=0, rata3_s=0, rata4_s=0, rata5_s=0;
        int rata1_s_osa=99999, rata2_s_osa=99999, rata3_s_osa=99999, rata4_s_osa=99999, rata5_s_osa=99999;
        int toluku=0;

        char rata1_ajaja[10];          //radan mestari kuski
        strcpy(rata1_ajaja,"-");

        char rata2_ajaja[10];
        strcpy(rata2_ajaja,"-");

        char rata3_ajaja[10];
        strcpy(rata3_ajaja,"-");

        char rata4_ajaja[10];
        strcpy(rata4_ajaja,"-");

        char rata5_ajaja[10];
        strcpy(rata5_ajaja,"-");
        
        char pl1_nimi[10];             //n„„ on n„it„ dorkien kuljettajien nimi„...
        strcpy(pl1_nimi,"Tuppu L.");

        char pl2_nimi[10];
        strcpy(pl2_nimi,"Makkara");

        char rata_nimi[10];
        strcpy(rata_nimi,"Nurmi");

        char rata1[10];
        strcpy(rata1,"Nurmi");         //n„„ pit„„s olla ratojen nimi„

        char rata2[10];
        strcpy(rata2,"Kasi");

        char rata3[10];
        strcpy(rata3,"-");

        char rata4[10];
        strcpy(rata4,"-");

        char rata5[10];
        strcpy(rata5,"-");

        allegro_init();            //asetetaan allegro p„„lle
        install_keyboard();        //asetetaan n„ppis p„„lle

        set_gfx_mode(GFX_AUTODETECT,320,200,0,0);    //n„ytt”tila

            // kuvien lataaminen
        nurmi=load_bmp("nurmi.bmp",pal);
        kasi=load_bmp("kasi.bmp",pal);
        porsche=load_bmp("Porsche.bmp",pal);
        corolla=load_bmp("corolla.bmp",pal);
        poliisi=load_bmp("Poliisi.bmp",pal);
        hilux=load_bmp("Hilux.bmp",pal);
        Lada=load_bmp("Lada.bmp",pal);
        Fighter=load_bmp("Fighter.bmp",pal);
        Ensivaste=load_bmp("Ensivaste.bmp",pal);
        SPR_Mobile=load_bmp("SPR_Mobile.bmp",pal);
        Jeeppi=load_bmp("Jeeppi.bmp",pal);
        Fiat=load_bmp("Fiat.bmp",pal);
        pl1_taus=load_bmp("alus_taus.bmp",pal);
        pl2_taus=load_bmp("alus_taus.bmp",pal);
        tummaa=load_bmp("tummaa.bmp",pal);
        kivi=load_bmp("kivi.bmp",pal);
        car=load_bmp("Car.bmp",pal);
        set_palette(pal);


//valikko alkaa
        while(toluku>-6)
        {
        luku=9;
        teksti=0;
        while(luku>-4)
        {

        if(teksti==0)         //tulostaa p„„valikon tekstit
        {
        blit(car,screen,0,0,0,0,car->w,car->h);
        gotoxy(10,5);
        printf(" *** p„„valikko *** ");
        gotoxy(12,10);
        printf("2)   2 pelaajaa  ");
        gotoxy(12,11);
        printf("T)     tietoa    ");
        gotoxy(12,12);
        printf("E)   enn„tyksi„  ");
        gotoxy(12,13);
        printf("V)     versiot   ");
        gotoxy(12,14);
        printf("S)     s„„d”t    ");
        gotoxy(12,15);
        printf("P) poistu pelist„");
        gotoxy(1,25);
        printf("V:0.003");
        gotoxy(25,25);
        printf("Tehnyt:Tuppu L.");
        }
        teksti++;
        
                while(a<1000000)
                {
                a=a+1;                             //valikko osuus alkaa
                }
                toluku=-5;                         //valikko muuttujien "nollaus"
                a=0;
                info=5;
                versio=5;
                moninpl=5;
                enkka=5;

                if(key[KEY_P])
                {
                toluku=-7;
                luku=-100;
                loppu=-7;
                }

                if(key[KEY_T])  //info osuus alkaa
                {
                blit(car,screen,0,0,0,0,car->w,car->h);
                gotoxy(10,1);
                printf(" ***   Tietoa   *** ");
                gotoxy(1,3);
                printf("PELI EI OLE VIELŽ VALMIS VERSIO! \nPelist„ tulee koko versio joskus vuoden sis„ll„ (aikaisintaan).\nPeliss„ voi pelata kaksin peli„, \nmutta ei yksin peli„. Valituksia,\nehdotuksia ja bugiista yms. voi \nl„hett„„ postia minulle,\nosoitteeseen: Tuppu_88@jippii.fi... \n\n20.5.2003 P.joki Finland TV:Tuppu L.\n\nKu oot lukenu niin painappa `ESC`");
                teksti=0;
                
                while(info>-2)
                {
                if(key[KEY_ESC])
                {
                info=-6;
                }                
                }                
                }                //info osuus loppuu
                
                if(key[KEY_V])  //versio homma alkaa
                {
                blit(car,screen,0,0,0,0,car->w,car->h);
                gotoxy(10,1);
                printf(" ***  Versiot  *** ");
                gotoxy(1,3);
                printf("\n\n <0,001 22.04.2003 \n 0,001  27.04.2003 \n 0,002  07.05.2003 \n 0,003  21.05.2003 \n\nku oot lukenu niin painappa `ESC`");
                teksti=0;
                
                while(versio>-2)
                {
                if(key[KEY_ESC])
                {
                versio=-6;
                }                
                }                
                }  //versio homma loppuu
                
                if(key[KEY_2])  //2PL valikko alkaa
                {                
                blit(car,screen,0,0,0,0,car->w,car->h);
                gotoxy(10,5);
                printf(" ***  monin peli *** ");
                gotoxy(14,8);
                printf("R)  Rata:%s",rata_nimi);
                gotoxy(14,9);
                printf("K)  Koneita:0");
                gotoxy(14,10);
                printf("1) PL1:Tuppu L.");
                gotoxy(14,11);
                printf("2) PL2:Makkara ");
                gotoxy(12,25);
                printf("Paina SPACEA");

                teksti=0;
                toluku=7;
                loppu=4;
                
                while(moninpl>-2)
                {

                if(key[KEY_R])
                {
                
                while(a<5000000) // <-- hidastus
                {
                a=a+1;
                }
                a=0;
                
                rata=rata+1;
                if(rata==0)rata=2;
                if(rata==3)rata=1;

                if (rata==1)strcpy(rata_nimi,rata1);
                if (rata==2)strcpy(rata_nimi,rata2);

                blit(car,screen,0,0,0,0,car->w,car->h);
                gotoxy(10,5);
                printf(" ***  monin peli *** ");
                gotoxy(14,8);
                printf("R)  Rata:%s",rata_nimi);
                gotoxy(14,9);
                printf("K)  Koneita:0");
                gotoxy(14,10);
                printf("1) PL1:Tuppu L.");
                gotoxy(14,11);
                printf("2) PL2:Makkara ");
                gotoxy(12,25);
                printf("Paina SPACEA");

                }
                
                if(key[KEY_SPACE])
                {
                loppu=7;
                luku=-100;
                toluku=-7;
                moninpl=-6;
                }
                
                if(key[KEY_ESC])
                {
                loppu=5;
                luku=100;
                toluku=7;
                moninpl=-6;
                }

                }
                
                }  //"2PL valikko loppuu
                if(key[KEY_E])  //enkka homma alkaa
                {
                blit(car,screen,0,0,0,0,car->w,car->h);
                gotoxy(10,5);
                
                printf(" *** Enn„tyksi„ *** ");

                while(rata1_s_osa>99)
                {
                rata1_s=rata1_s+1;
                rata1_s_osa=rata1_s_osa-100;
                }

                while(rata2_s_osa>99)
                {
                rata2_s=rata2_s+1;
                rata2_s_osa=rata2_s_osa-100;
                }

                while(rata3_s_osa>99)
                {
                rata3_s=rata3_s+1;
                rata3_s_osa=rata3_s_osa-100;
                }

                while(rata4_s_osa>99)
                {
                rata4_s=rata4_s+1;
                rata4_s_osa=rata4_s_osa-100;
                }

                while(rata5_s_osa>99)
                {
                rata5_s=rata5_s+1;
                rata5_s_osa=rata5_s_osa-100;
                }

                gotoxy(1,8);
                printf("Paikka:");
                gotoxy(15,8);
                printf("Kuski:");
                gotoxy(26,8);
                printf("Aika:");
                gotoxy(1,10);
                printf("%s",rata1);
                gotoxy(1,11);
                printf("%s",rata2);
                gotoxy(1,12);
                printf("%s",rata3);
                gotoxy(1,13);
                printf("%s",rata4);
                gotoxy(1,14);
                printf("%s",rata5);
                gotoxy(15,10);
                printf("%s",rata1_ajaja);
                gotoxy(15,11);
                printf("%s",rata2_ajaja);
                gotoxy(15,12);
                printf("%s",rata3_ajaja);
                gotoxy(15,13);
                printf("%s",rata4_ajaja);
                gotoxy(15,14);
                printf("%s",rata5_ajaja);
                gotoxy(26,10);
                printf("%d.%d sekuntia",rata1_s,rata1_s_osa);
                gotoxy(26,11);
                printf("%d.%d sekuntia",rata2_s,rata2_s_osa);
                gotoxy(26,12);
                printf("%d.%d sekuntia",rata3_s,rata3_s_osa);
                gotoxy(26,13);
                printf("%d.%d sekuntia",rata4_s,rata4_s_osa);
                gotoxy(26,14);
                printf("%d.%d sekuntia",rata5_s,rata5_s_osa);
                teksti=0;

                while(rata1_s>0)
                {
                rata1_s=rata1_s-1;
                rata1_s_osa=rata1_s_osa+100;
                }

                while(rata2_s>0)
                {
                rata2_s=rata2_s-1;
                rata2_s_osa=rata2_s_osa+100;
                }

                while(rata3_s>0)
                {
                rata3_s=rata3_s-1;
                rata3_s_osa=rata3_s_osa+100;
                }

                while(rata4_s>0)
                {
                rata4_s=rata4_s-1;
                rata4_s_osa=rata4_s_osa+100;
                }

                while(rata5_s>0)
                {
                rata5_s=rata5_s-1;
                rata5_s_osa=rata5_s_osa+100;
                }

                teksti=0;
                
                while(enkka>-2)
                {
                if(key[KEY_ESC])
                {
                enkka=-6;
                }                
                }
                }  //enkka homma loppuu
        }         //valikko osuus loppuu

        if(rata==1) tausta=nurmi;      //katsastetaan oikea radan kuva
        if(rata==2) tausta=kasi;

        pl1=hilux;              //pelaajien kulkuneuvot
        pl2=Ensivaste;

        //tarpeellinen ettei tuu valkosia l”nttej„ autojen kohtaan...
        
        blit(tausta,pl1_taus,x,y,0,0,pl1_taus->w,pl1_taus->h);
        blit(tausta,pl2_taus,x2,y2,0,0,pl2_taus->w,pl2_taus->h);
        
        draw_sprite(tausta,pl1,x,y);      //pist„„ koneen koordinaatteihin
        draw_sprite(tausta,pl2,x2,y2);
        px=x+10;
        py=y+10;
        
        if(vana==1) draw_sprite(tausta,tummaa,px,py);         ////Per„luisut
        
           //peliosuus
gotoxy(1,24);
printf("                                        ");
gotoxy(1,25);
printf("                                        ");
        while(loppu>5){

                while(a<looppi)
        {
        a++;
        }
        a=0;

                if(key[KEY_Z])
                looppi=looppi*1.05;
                if(key[KEY_X])
                looppi=looppi/1.05;


                //tarpeellinen ettei tuu maalit tielle..
                blit(pl1_taus,tausta,0,0,x,y,pl1_taus->w,pl1_taus->h);
                blit(pl2_taus,tausta,0,0,x2,y2,pl2_taus->w,pl2_taus->h);

                switch (ohjaus)
                {
                case 5 :
                if(key[KEY_LEFT]) pl1_asento=pl1_asento-1;    //k„„nt„minen
                if(key[KEY_A]) pl2_asento=pl2_asento-1;
                if(key[KEY_RIGHT]) pl1_asento=pl1_asento+1;
                if(key[KEY_D]) pl2_asento=pl2_asento+1;
                ohjaus=0;
                break;

                default :
                ohjaus++;
                break;
                }


                if(key[KEY_UP])  //eteenp„in lento
                switch (pl1_asento)
                {
                case 2 :
                pl1_nopeus_y=pl1_nopeus_y-2*nopeus;     //kone yl”sp„in
                break;
                
                case 3 :
                pl1_nopeus_y=pl1_nopeus_y-2*nopeus;
                pl1_nopeus_x=pl1_nopeus_x+1*nopeus;
                break;

                case 4 :
                pl1_nopeus_y=pl1_nopeus_y-2*nopeus;
                pl1_nopeus_x=pl1_nopeus_x+2*nopeus;     //kone yl”s-oikeelle
                break;

                case 5 :
                pl1_nopeus_y=pl1_nopeus_y-1*nopeus;
                pl1_nopeus_x=pl1_nopeus_x+2.0*nopeus;
                break;

                case 6 :
                pl1_nopeus_x=pl1_nopeus_x+2*nopeus;     //kone oikalle
                break;

                case 7 :
                pl1_nopeus_x=pl1_nopeus_x+2.0*nopeus;
                pl1_nopeus_y=pl1_nopeus_y+1*nopeus;
                break;

                case 8 :
                pl1_nopeus_x=pl1_nopeus_x+2*nopeus;
                pl1_nopeus_y=pl1_nopeus_y+2*nopeus;     //kone alas-oikalle
                break;

                case 9 :
                pl1_nopeus_x=pl1_nopeus_x+1.0*nopeus;
                pl1_nopeus_y=pl1_nopeus_y+2.0*nopeus;
                break;

                case 10 :
                pl1_nopeus_y=pl1_nopeus_y+2*nopeus;     //kone alasp„in
                break;

                case 11 :
                pl1_nopeus_y=pl1_nopeus_y+2.0*nopeus;
                pl1_nopeus_x=pl1_nopeus_x-1.0*nopeus;
                break;

                case 12 :
                pl1_nopeus_y=pl1_nopeus_y+2*nopeus;
                pl1_nopeus_x=pl1_nopeus_x-2*nopeus;     //kone alas-vasemmalle
                break;

                case 13 :
                pl1_nopeus_y=pl1_nopeus_y+1.0*nopeus;
                pl1_nopeus_x=pl1_nopeus_x-2.0*nopeus;
                break;

                case 14 :
                pl1_nopeus_x=pl1_nopeus_x-2*nopeus;     //kone vasemmalle
                break;

                case 15 :
                pl1_nopeus_x=pl1_nopeus_x-2.0*nopeus;
                pl1_nopeus_y=pl1_nopeus_y-1.0*nopeus;
                break;

                case 16 :
                pl1_nopeus_x=pl1_nopeus_x-2*nopeus;
                pl1_nopeus_y=pl1_nopeus_y-2*nopeus;     //kone yl”s-vasemmalle
                break;

                case 17 :
                pl1_nopeus_x=pl1_nopeus_x-1.0*nopeus;
                pl1_nopeus_y=pl1_nopeus_y-2.0*nopeus;
                break;

                }
                if(key[KEY_W])  //eteenp„in lento
                switch (pl2_asento)
                {

                case 2 :
                pl2_nopeus_y=pl2_nopeus_y-2*nopeus;     //kone yl”sp„in
                break;

                case 3 :
                pl2_nopeus_y=pl2_nopeus_y-2.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x+1.0*nopeus;
                break;

                case 4 :
                pl2_nopeus_y=pl2_nopeus_y-2.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x+2.0*nopeus;     //kone yl”s-oikeelle
                break;

                case 5 :
                pl2_nopeus_y=pl2_nopeus_y-1.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x+2.0*nopeus;
                break;

                case 6 :
                pl2_nopeus_x=pl2_nopeus_x+2*nopeus;     //kone oikalle
                break;

                case 7 :
                pl2_nopeus_x=pl2_nopeus_x+2.0*nopeus;
                pl2_nopeus_y=pl2_nopeus_y+1.0*nopeus;
                break;

                case 8 :
                pl2_nopeus_x=pl2_nopeus_x+2*nopeus;
                pl2_nopeus_y=pl2_nopeus_y+2*nopeus;     //kone alas-oikalle
                break;

                case 9 :
                pl2_nopeus_x=pl2_nopeus_x+1.0*nopeus;
                pl2_nopeus_y=pl2_nopeus_y+2.0*nopeus;
                break;

                case 10 :
                pl2_nopeus_y=pl2_nopeus_y+2*nopeus;     //kone alasp„in
                break;

                case 11 :
                pl2_nopeus_y=pl2_nopeus_y+2.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x-1.0*nopeus;
                break;

                case 12 :
                pl2_nopeus_y=pl2_nopeus_y+2*nopeus;
                pl2_nopeus_x=pl2_nopeus_x-2*nopeus;     //kone alas-vasemmalle
                break;

                case 13 :
                pl2_nopeus_y=pl2_nopeus_y+1.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x-2.0*nopeus;
                break;

                case 14 :
                pl2_nopeus_x=pl2_nopeus_x-2*nopeus;     //kone vasemmalle
                break;

                case 15 :
                pl2_nopeus_x=pl2_nopeus_x-2.0*nopeus;
                pl2_nopeus_y=pl2_nopeus_y-1.0*nopeus;
                break;

                case 16 :
                pl2_nopeus_x=pl2_nopeus_x-2*nopeus;
                pl2_nopeus_y=pl2_nopeus_y-2*nopeus;     //kone yl”s-vasemmalle
                break;

                case 17 :
                pl2_nopeus_x=pl2_nopeus_x-1.0*nopeus;
                pl2_nopeus_y=pl2_nopeus_y-2.0*nopeus;
                break;
                }
                
                if(key[KEY_DOWN])//pakitus
                switch (pl1_asento)
                {

                case 2 :
                pl1_nopeus_y=pl1_nopeus_y+2*nopeus;     //kone yl”sp„in
                break;

                case 3 :
                pl1_nopeus_y=pl1_nopeus_y+2.0*nopeus;
                pl1_nopeus_x=pl1_nopeus_x-1.0*nopeus;
                break;

                case 4 :
                pl1_nopeus_y=pl1_nopeus_y+2*nopeus;
                pl1_nopeus_x=pl1_nopeus_x-2*nopeus;
                break;

                case 5 :
                pl1_nopeus_y=pl1_nopeus_y+1.0*nopeus;
                pl1_nopeus_x=pl1_nopeus_x-2.0*nopeus;
                break;

                case 6 :
                pl1_nopeus_x=pl1_nopeus_x-2*nopeus;     //kone oikeelle
                break;

                case 7 :
                pl1_nopeus_y=pl1_nopeus_y-1.0*nopeus;
                pl1_nopeus_x=pl1_nopeus_x-2.0*nopeus;
                break;

                case 8 :
                pl1_nopeus_y=pl1_nopeus_y-2*nopeus;
                pl1_nopeus_x=pl1_nopeus_x-2*nopeus;     //kone oikeelle
                break;

                case 9 :
                pl1_nopeus_y=pl1_nopeus_y-2.0*nopeus;
                pl1_nopeus_x=pl1_nopeus_x-1.0*nopeus;
                break;

                case 10 :
                pl1_nopeus_y=pl1_nopeus_y-2*nopeus;     //kone alasp„in
                break;

                case 11 :
                pl1_nopeus_y=pl1_nopeus_y-2.0*nopeus;
                pl1_nopeus_x=pl1_nopeus_x+1.0*nopeus;
                break;

                case 12 :
                pl1_nopeus_y=pl1_nopeus_y-2*nopeus;
                pl1_nopeus_x=pl1_nopeus_x+2*nopeus;     //kone alasp„in
                break;

                case 13 :
                pl1_nopeus_y=pl1_nopeus_y-1.0*nopeus;
                pl1_nopeus_x=pl1_nopeus_x+2.0*nopeus;
                break;

                case 14 :
                pl1_nopeus_x=pl1_nopeus_x+2*nopeus;     //kone vasemmalle
                break;

                case 15 :
                pl1_nopeus_y=pl1_nopeus_y+1.0*nopeus;
                pl1_nopeus_x=pl1_nopeus_x+2.0*nopeus;
                break;

                case 16 :
                pl1_nopeus_x=pl1_nopeus_x+2*nopeus;
                pl1_nopeus_y=pl1_nopeus_y+2*nopeus;     //kone vasemmalle
                break;

                case 17 :
                pl1_nopeus_x=pl1_nopeus_x+1.0*nopeus;
                pl1_nopeus_y=pl1_nopeus_y+2.0*nopeus;
                break;
                }

                                if(key[KEY_S])//pakitus
                switch (pl2_asento)
                {

                case 2 :
                pl2_nopeus_y=pl2_nopeus_y+2*nopeus;     //kone yl”sp„in
                break;

                case 3 :
                pl2_nopeus_y=pl2_nopeus_y+2.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x-1.0*nopeus;
                break;

                case 4 :
                pl2_nopeus_y=pl2_nopeus_y+2*nopeus;
                pl2_nopeus_x=pl2_nopeus_x-2*nopeus;
                break;

                case 5 :
                pl2_nopeus_y=pl2_nopeus_y+1.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x-2.0*nopeus;
                break;

                case 6 :
                pl2_nopeus_x=pl2_nopeus_x-2*nopeus;     //kone oikeelle
                break;

                case 7 :
                pl2_nopeus_y=pl2_nopeus_y-1.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x-2.0*nopeus;
                break;

                case 8 :
                pl2_nopeus_y=pl2_nopeus_y-2*nopeus;
                pl2_nopeus_x=pl2_nopeus_x-2*nopeus;     //kone oikeelle
                break;

                case 9 :
                pl2_nopeus_y=pl2_nopeus_y-2.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x-1.0*nopeus;
                break;

                case 10 :
                pl2_nopeus_y=pl2_nopeus_y-2*nopeus;     //kone alasp„in
                break;

                case 11 :
                pl2_nopeus_y=pl2_nopeus_y-2.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x+1.0*nopeus;
                break;

                case 12 :
                pl2_nopeus_y=pl2_nopeus_y-2*nopeus;
                pl2_nopeus_x=pl2_nopeus_x+2*nopeus;     //kone alasp„in
                break;

                case 13 :
                pl2_nopeus_y=pl2_nopeus_y-1.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x+2.0*nopeus;
                break;

                case 14 :
                pl2_nopeus_x=pl2_nopeus_x+2*nopeus;     //kone vasemmalle
                break;

                case 15 :
                pl2_nopeus_y=pl2_nopeus_y+1.0*nopeus;
                pl2_nopeus_x=pl2_nopeus_x+2.0*nopeus;
                break;

                case 16 :
                pl2_nopeus_x=pl2_nopeus_x+2*nopeus;
                pl2_nopeus_y=pl2_nopeus_y+2*nopeus;     //kone vasemmalle
                break;

                case 17 :
                pl2_nopeus_x=pl2_nopeus_x+1.0*nopeus;
                pl2_nopeus_y=pl2_nopeus_y+2.5*nopeus;
                break;
                }

                if (x<1) pl1_nopeus_x=0;
                if (x<1) x=1;
                if (y<-5) pl1_nopeus_y=0;
                if (y<-5) y=-4;                  //seiniin t”rm„„minen
                if (x2<1) pl2_nopeus_x=0;
                if (x2<1) x2=1;
                if (y2<-5) pl2_nopeus_y=0;
                if (y2<-5) y2=-4;
                if (x>290) pl1_nopeus_x=0;
                if (x>290) x=290;
                if (y>155) pl1_nopeus_y=0;
                if (y>155) y=154;
                if (x2>290) pl2_nopeus_x=0;
                if (x2>290) x2=290;
                if (y2>155) pl2_nopeus_y=0;
                if (y2>155) y2=154;

                if(key[KEY_ESC])
                {
                gotoxy(13,14);
                printf("lopetetaanko (K/E)");
                while(lopetetaanko<0)
                {
                if(key[KEY_K])
                {
                toluku=7;
                loppu=5;
                lopetetaanko=5;
                }
                if(key[KEY_E])
                {
                lopetetaanko=5;
                }
                }
                lopetetaanko=-5;
                }

                while(turha<5)      //Kivien piirto
                {
                draw_sprite(tausta,kivi,kivet[turha].x_min,kivet[turha].y_min);
                turha++;
                }
                turha=0;

                if (y > scp_1_y_min && y < scp_1_y_max && x > scp_1_x_min && x < scp_1_x_max)
                {
                scp_pl1++;         //pl1 tarkistuspisteet
                }

                if (scp_pl1==1)
                {
                scp_1_y_min=scp2_y_min;
                scp_1_y_max=scp2_y_max;
                scp_1_x_min=scp2_x_min;
                scp_1_x_max=scp2_x_max;
                }

                if (scp_pl1==2)
                {
                scp_1_y_min=scp3_y_min;
                scp_1_y_max=scp3_y_max;
                scp_1_x_min=scp3_x_min;
                scp_1_x_max=scp3_x_max;
                }

                if (scp_pl1==3)
                {
                scp_1_y_min=scp4_y_min;
                scp_1_y_max=scp4_y_max;
                scp_1_x_min=scp4_x_min;
                scp_1_x_max=scp4_x_max;
                }

                if (scp_pl1==4)
                {
                scp_1_y_min=scp5_y_min;
                scp_1_y_max=scp5_y_max;
                scp_1_x_min=scp5_x_min;
                scp_1_x_max=scp5_x_max;
                }

                if (scp_pl1==5)
                {
                scp_1_y_min=scp1_y_min;
                scp_1_y_max=scp1_y_max;
                scp_1_x_min=scp1_x_min;
                scp_1_x_max=scp1_x_max;
                scp_pl1=0;
                kierros_pl1++;
                pl1_s_osa=pl1_s_osa+pl1_s*100;

                if (pl1_s_osa<rata1_s_osa)
                {                                 //t„„ asettaa enkka ajat ratoohin
                if(rata==1)
                {
                rata1_s_osa=pl1_s_osa;
                strcpy(rata1_ajaja,pl1_nimi);
                }
                }
                
                if (pl1_s_osa<rata2_s_osa)
                {
                if(rata==2)
                {
                rata2_s_osa=pl1_s_osa;
                strcpy(rata2_ajaja,pl1_nimi);
                }
                }
                
                pl1_s_osa=0;
                pl1_s=0;
                }

                if (y2> scp_2_y_min && y2< scp_2_y_max && x2> scp_2_x_min && x2< scp_2_x_max)
                {
                scp_pl2++;         //pl2 tarkistuspisteet
                }

                if (scp_pl2==1)
                {
                scp_2_y_min=scp2_y_min;
                scp_2_y_max=scp2_y_max;
                scp_2_x_min=scp2_x_min;
                scp_2_x_max=scp2_x_max;
                }

                if (scp_pl2==2)
                {
                scp_2_y_min=scp3_y_min;
                scp_2_y_max=scp3_y_max;
                scp_2_x_min=scp3_x_min;
                scp_2_x_max=scp3_x_max;
                }

                if (scp_pl2==3)
                {
                scp_2_y_min=scp4_y_min;
                scp_2_y_max=scp4_y_max;
                scp_2_x_min=scp4_x_min;
                scp_2_x_max=scp4_x_max;
                }

                if (scp_pl2==4)
                {
                scp_2_y_min=scp5_y_min;
                scp_2_y_max=scp5_y_max;
                scp_2_x_min=scp5_x_min;
                scp_2_x_max=scp5_x_max;
                }

                if (scp_pl2==5)
                {
                scp_2_y_min=scp1_y_min;
                scp_2_y_max=scp1_y_max;
                scp_2_x_min=scp1_x_min;
                scp_2_x_max=scp1_x_max;
                scp_pl2=0;
                kierros_pl2++;
                pl2_s_osa=pl2_s_osa+pl2_s*100;

                if (pl2_s_osa<rata1_s_osa)
                {
                if(rata==1)
                {
                rata1_s_osa=pl2_s_osa;
                strcpy(rata1_ajaja,pl2_nimi);
                }
                }
                
                if (pl2_s_osa<rata2_s_osa)
                {
                if(rata==2)
                {
                rata2_s_osa=pl2_s_osa;
                strcpy(rata2_ajaja,pl2_nimi);
                }
                }
                
                pl2_s_osa=0;
                pl2_s=0;
                }

                pl1_nopeus_y=pl1_nopeus_y+vetovoima;    //vetovoiman lasku
                pl2_nopeus_y=pl2_nopeus_y+vetovoima;

                pl1_nopeus_x=pl1_nopeus_x*1;         //kitkaa peliin
                pl2_nopeus_y=pl2_nopeus_y*1;
                pl1_nopeus_x=pl1_nopeus_x*1;
                pl2_nopeus_y=pl2_nopeus_y*1;

                y=y+pl1_nopeus_y;  //liikkuminen korkeus suunnassa
                y2=y2+pl2_nopeus_y;
                x=x+pl1_nopeus_x;  //liikkuminen sivuttais suunnassa
                x2=x2+pl2_nopeus_x;


                //ottaa taustan palan spriten taustaksi

                blit(tausta,pl1_taus,x,y,0,0,pl1_taus->w,pl1_taus->h); //toinen syy ikkuna syy!!!
                blit(tausta,pl2_taus,x2,y2,0,0,pl2_taus->w,pl2_taus->h);

                switch (pl1_asento)           //piirt„„ oikeen asennon
                {
                case 1:
                if(pl1_asento=1) pl1_asento=17;
                break;
                case 2:
                rotate_sprite(tausta,pl1,x,y,itofix(1));     //yl”sp„in
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(1));
                pl1_nopeus_x=pl1_nopeus_x*0.9;      //<-- nuo jutut johtuu renkaitten puskemisesta (ne on sivusuunnassa kulku suuntaan)
                break;
                case 3:
                rotate_sprite(tausta,pl1,x,y,itofix(16));
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(16));
                pl1_nopeus_x=pl1_nopeus_x*0.95;
                pl1_nopeus_y=pl1_nopeus_y*0.95;
                break;
                case 4:
                rotate_sprite(tausta,pl1,x,y,itofix(32));    //yl„-oikealle
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(32));
                pl1_nopeus_x=pl1_nopeus_x*0.97;
                pl1_nopeus_y=pl1_nopeus_y*0.97;
                break;
                case 5:
                rotate_sprite(tausta,pl1,x,y,itofix(48));
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(48));
                pl1_nopeus_x=pl1_nopeus_x*0.95;
                pl1_nopeus_y=pl1_nopeus_y*0.95;
                break;
                case 6:
                rotate_sprite(tausta,pl1,x,y,itofix(64));    //oikeallep„in
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(64));
                pl1_nopeus_y=pl1_nopeus_y*0.9;
                break;
                case 7:
                rotate_sprite(tausta,pl1,x,y,itofix(80));
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(80));
                pl1_nopeus_y=pl1_nopeus_y*0.95;
                pl1_nopeus_x=pl1_nopeus_x*0.95;
                break;
                case 8:
                rotate_sprite(tausta,pl1,x,y,itofix(96));    //ala-oikealle
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(96));
                pl1_nopeus_y=pl1_nopeus_y*0.97;
                pl1_nopeus_x=pl1_nopeus_x*0.97;
                break;
                case 9:
                rotate_sprite(tausta,pl1,x,y,itofix(112));
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(112));
                pl1_nopeus_y=pl1_nopeus_y*0.95;
                pl1_nopeus_x=pl1_nopeus_x*0.95;
                break;
                case 10:
                rotate_sprite(tausta,pl1,x,y,itofix(128));     //alasp„in
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(128));
                pl1_nopeus_x=pl1_nopeus_x*0.9;
                break;
                case 11:
                rotate_sprite(tausta,pl1,x,y,itofix(144));
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(144));
                pl1_nopeus_x=pl1_nopeus_x*0.95;
                pl1_nopeus_y=pl1_nopeus_y*0.95;
                break;
                case 12:
                rotate_sprite(tausta,pl1,x,y,itofix(160));    //ala-vasemalle
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(160));
                pl1_nopeus_x=pl1_nopeus_x*0.97;
                pl1_nopeus_y=pl1_nopeus_y*0.97;
                break;
                case 13:
                rotate_sprite(tausta,pl1,x,y,itofix(176));
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(176));
                pl1_nopeus_x=pl1_nopeus_x*0.95;
                pl1_nopeus_y=pl1_nopeus_y*0.95;
                break;
                case 14:
                rotate_sprite(tausta,pl1,x,y,itofix(192));    //vasemmalle
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(192));
                pl1_nopeus_y=pl1_nopeus_y*0.9;
                break;
                case 15:
                rotate_sprite(tausta,pl1,x,y,itofix(208));
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(208));
                pl1_nopeus_y=pl1_nopeus_y*0.95;
                pl1_nopeus_x=pl1_nopeus_x*0.95;
                break;
                case 16:
                rotate_sprite(tausta,pl1,x,y,itofix(224));    //yl„-vasemmalle
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(224));
                pl1_nopeus_y=pl1_nopeus_y*0.97;
                pl1_nopeus_x=pl1_nopeus_x*0.97;
                break;
                case 17:
                rotate_sprite(tausta,pl1,x,y,itofix(240));    //oikeallep„in
                if(vana==1) rotate_sprite(tausta,tummaa,x,y,itofix(240));
                pl1_nopeus_y=pl1_nopeus_y*0.95;
                pl1_nopeus_x=pl1_nopeus_x*0.95;
                break;
                case 18:
                pl1_asento=2;
                break;
                }
                      switch (pl2_asento)           //piirt„„ oikeen asennon
                {
                case 1:
                if(pl2_asento=1) pl2_asento=17;          //renkaitten puskeminen...
                break;
                case 2:
                rotate_sprite(tausta,pl2,x2,y2,itofix(1));     //yl”sp„in
                pl2_nopeus_x=pl2_nopeus_x*0.9;
                break;
                case 3:
                rotate_sprite(tausta,pl2,x2,y2,itofix(16));
                pl2_nopeus_x=pl2_nopeus_x*0.97;
                pl2_nopeus_y=pl2_nopeus_y*0.95;
                break;
                case 4:
                rotate_sprite(tausta,pl2,x2,y2,itofix(32));    //yl„-oikealle
                pl2_nopeus_x=pl2_nopeus_x*0.97;
                pl2_nopeus_y=pl2_nopeus_y*0.97;
                break;
                case 5:
                rotate_sprite(tausta,pl2,x2,y2,itofix(48));
                pl2_nopeus_x=pl2_nopeus_x*0.95;
                pl2_nopeus_y=pl2_nopeus_y*0.95;
                break;
                case 6:
                rotate_sprite(tausta,pl2,x2,y2,itofix(64));    //oikeallep„in
                pl2_nopeus_y=pl2_nopeus_y*0.9;
                break;
                case 7:
                rotate_sprite(tausta,pl2,x2,y2,itofix(80));
                pl2_nopeus_y=pl2_nopeus_y*0.95;
                pl2_nopeus_x=pl2_nopeus_x*0.95;
                break;
                case 8:
                rotate_sprite(tausta,pl2,x2,y2,itofix(96));    //ala-oikealle
                pl2_nopeus_y=pl2_nopeus_y*0.97;
                pl2_nopeus_x=pl2_nopeus_x*0.97;
                break;
                case 9:
                rotate_sprite(tausta,pl2,x2,y2,itofix(112));
                pl2_nopeus_y=pl2_nopeus_y*0.95;
                pl2_nopeus_x=pl2_nopeus_x*0.95;
                break;
                case 10:
                rotate_sprite(tausta,pl2,x2,y2,itofix(128));     //alasp„in
                pl2_nopeus_x=pl2_nopeus_x*0.9;
                break;
                case 11:
                rotate_sprite(tausta,pl2,x2,y2,itofix(144));
                pl2_nopeus_x=pl2_nopeus_x*0.95;
                pl2_nopeus_y=pl2_nopeus_y*0.95;
                break;
                case 12:
                rotate_sprite(tausta,pl2,x2,y2,itofix(160));    //ala-vasemalle
                pl2_nopeus_x=pl2_nopeus_x*0.97;
                pl2_nopeus_y=pl2_nopeus_y*0.97;
                break;
                case 13:
                rotate_sprite(tausta,pl2,x2,y2,itofix(176));
                pl2_nopeus_x=pl2_nopeus_x*0.95;
                pl2_nopeus_y=pl2_nopeus_y*0.95;
                break;
                case 14:
                rotate_sprite(tausta,pl2,x2,y2,itofix(192));    //vasemmalle
                pl2_nopeus_y=pl2_nopeus_y*0.9;
                break;
                case 15:
                rotate_sprite(tausta,pl2,x2,y2,itofix(208));
                pl2_nopeus_y=pl2_nopeus_y*0.95;
                pl2_nopeus_x=pl2_nopeus_x*0.95;
                break;
                case 16:
                rotate_sprite(tausta,pl2,x2,y2,itofix(224));    //yl„-vasemmalle
                pl2_nopeus_y=pl2_nopeus_y*0.97;
                pl2_nopeus_x=pl2_nopeus_x*0.97;
                break;
                case 17:
                rotate_sprite(tausta,pl2,x2,y2,itofix(240));    //oikeallep„in
                pl2_nopeus_y=pl2_nopeus_y*0.95;
                pl2_nopeus_x=pl2_nopeus_x*0.95;
                break;
                case 18:
                pl2_asento=2;
                break;
                case 100 :
                pl2_asento=17;
                break;
                }
                
                // Ja koko komeus n„yt”lle
                blit(tausta,screen,0,0,0,0,tausta->w, tausta->h);

                if (pl1_s_osa>97)
                {
                pl1_s++;
                pl1_s_osa=0;
                }
                if (pl2_s_osa>97)
                {
                pl2_s++;
                pl2_s_osa=0;
                }

                pl1_s_osa=pl1_s_osa+3;
                pl2_s_osa=pl2_s_osa+3;

                gotoxy(1,24);
                printf("%s %d.%d  ",pl1_nimi,pl1_s,pl1_s_osa);
                gotoxy(22,24);
                printf("%s %d.%d  ",pl2_nimi,pl2_s,pl2_s_osa);
                gotoxy(1,25);
                printf("kierros: %d (%d/5)",kierros_pl1,scp_pl1);
                gotoxy(22,25);
                printf("kierros: %d (%d/5)",kierros_pl2,scp_pl2);

                
        }          //peli homma loppuu

        if(loppu==5)
        {
        nurmi=load_bmp("nurmi.bmp",pal);   //t„nne sitte pelin aikaasten kuvien "nollaus"
        kasi=load_bmp("kasi.bmp",pal);

        scp_pl1=0;                         //t„nne sitte pelin aikaasten muuttujien "nollaus"
        scp_pl2=0;
        kierros_pl1=0;
        kierros_pl2=0;
        pl1_s_osa=0;
        pl2_s_osa=0;
        pl1_s=0;
        pl2_s=0;
        pl1_asento=14;
        pl2_asento=14;
        pl1_nopeus_y=0;
        pl2_nopeus_y=0;
        pl1_nopeus_x=0;
        pl2_nopeus_x=0;

        luku=9;
        x=150;
        x2=153;
        y=115;
        y2=133;
        }
        
        }                                 //peli loppuu t„h„n (pist„ loppu tekstit, joskus (;...) THE END

        allegro_exit();                   //suljetaan ny sitte lopukki

        return(0);
}
