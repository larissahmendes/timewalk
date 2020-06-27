#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <TH1.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <math.h>
#include <map>

#define VERBOSE 0
using namespace std;

int vpx_decode_timewalk_vtploop (char *dirname, bool skip_header=false, long maxpackets=100000000000){

    UInt_t sphdr_id;
    UInt_t sphdr_size;
    UInt_t *fullheader;
    Int_t  retval;
    Int_t cnt = 0;
    ULong64_t ethword[3];  // one packet consists of 3 groups of 8 bytes, and contains 4 packets of 6 bytes
    ULong64_t packet[4];
    ULong64_t tmpword, firstval, lastval;
    int hdr, bxid, spaddr, hitmap, delta;
    int pixcnt = 0;
    int hcnt = 0;
    int stats[4] = {0,0,0,0};
    int bitstats[30];
    int pcnt = 0;
    for (int i=0; i<30; ++i){
		 bitstats[i] = 0;}

    TFile *outputfile = new TFile("/eos/user/l/lmendes/twalk/outputfile_update_martin_positive_r7c2.root", "RECREATE");
    unsigned int emptyPacket = 0x12BEEE00;

    gStyle->SetOptStat("e");

    TH2F *h2 = new TH2F("h2","hitmap;column;row", 256, -0.5, 255.5, 256, -0.5, 255.5);
    TH2F *hvtptwAllperpix[65000]={NULL};
    char title[8000], name[4000];
   
    std::map<int, std::map <int, TH2F*> > hvtptwAllPerPix; 

    TH2F *hvtptwAll=NULL;     

    for (int icol=2; icol<256; icol+=8){ 
    for (int irow=7; irow<256; irow+=8){
      for (int ivtp = 513; ivtp < 1025; ivtp++) {
	      delta = fabs(ivtp-512);
          //delta = ivtp-512;
	      for (int phase = 0; phase<=15; phase++) { 
            char sstr[15];
		    char sstrvtp[15];
		    sprintf(sstr,"phase%d_", phase);
            
		    sprintf(sstrvtp,"vtp%d_", ivtp);
		    //printf("vtp%d_\n", ivtp);
            DIR *dir;
            struct dirent *ent;

		    if ((dir = opendir (dirname)) != NULL) {
			    // print all the files and directories within directory 
			    while ((ent = readdir (dir)) != NULL) {
                //cout << sstr << "  " << ent->d_name << endl;
				    if ( strstr(ent->d_name, sstr) ) {         
					    if ( strstr(ent->d_name, sstrvtp) ) {         

                            char filename[4000];
						    sprintf(filename, "%s/%s", dirname, ent->d_name);
                            FILE *fp;
						    fp = fopen(filename, "r");
                            cout << filename << endl;
						    if (fp == NULL) { cout << "can not open file: " << filename << endl; return -1;}
						    //if (fp == NULL) { cout << "can not open file: " << filename << endl; continue;}

                            double   min = 0   - 1.0/16.0/2.0; 
                            double   max = 300 - 1.0/16.0/2.0;
                            double Nbins = 300*16;
                            cout << "Nbins " << Nbins << " min "<< min << " max " <<  max << endl;

                            sprintf(name,"htwAllperpix_r%d_c%d", irow, icol);
						    sprintf(title,"Pixel (%d,%d) - Positive #Delta VTP; #Delta VTP; bxid+(1.0/16)*phase", irow, icol); 
                            if(hvtptwAllPerPix[icol][irow] == NULL)hvtptwAllPerPix[icol][irow] = new TH2F(name, title, 512, -0.5, 511.5, Nbins, min,max);
                            cout <<  "name hvtptwAllperpix  "<< name << " Row = " << irow << " Column = " << icol << endl << endl;
						    
                            if (!skip_header) {
							    retval = fread( &sphdr_id, sizeof(UInt_t), 1, fp);
							    retval = fread( &sphdr_size, sizeof(UInt_t), 1, fp);
							    cout << hex << sphdr_id << dec << endl;
							    cout << "header size " << sphdr_size << endl; 
							    if (sphdr_size > 663050) sphdr_size = 663040;
							    fullheader = new UInt_t[sphdr_size/sizeof(UInt_t)];
							    if (fullheader == 0) { cout << "failed to allocate memory for header " << endl; return -1; }

							    retval = fread ( fullheader+2, sizeof(UInt_t), sphdr_size/sizeof(UInt_t) -2, fp);
							    fullheader[0] = sphdr_id;
							    fullheader[1] = sphdr_size;
						    }

						    int weight = 1;

						    while (!feof(fp) && (pcnt<maxpackets)) {
							    retval = fread( &ethword, 3*sizeof(ULong64_t), 1, fp);
							    if (!retval) break;
							    else pcnt+=4;
							    packet[0] =    ethword[0] & 0x0000FFFFFFFFFFFFull;
							    packet[1] = ( ((ULong64_t)(ethword[0]>>48)) & 0x000000000000FFFFull )  |  ( ((ULong64_t)(ethword[1]<<16)) & 0x0000FFFFFFFF0000ull );
							    packet[2] = ( ((ULong64_t)(ethword[1]>>32)) & 0x00000000FFFFFFFFull )  |  ( ((ULong64_t)(ethword[2]<<32)) & 0x0000FFFF00000000ull );
							    packet[3] =   ((ULong64_t)(ethword[2]>>16)) & 0x0000FFFFFFFFFFFFull ;
							    if ( 1) {
								    int hcnt = 0; 
								    for (int i=0; i<4; ++i) {
									    if ( packet[i] != 0) {
										    hcnt++;
										    pixcnt++;
										    bxid =  (packet[i]>>8) & 0x1FF;
										    spaddr =  (packet[i]>>17) & 0x1FFF;
										    hitmap = packet[i] & 0xFF ; 
										    if (VERBOSE && (spaddr = 0x1feb)) cout << i << hex << ": pixel data, bxid: " << bxid << "  " 
											    << "SP addr: " << spaddr << "  " 
												    << "hit map: " << hitmap << dec << endl; 
										    int spcol = (spaddr>>6) & 0x7F; 
										    int sprow = spaddr & 0x3F; 
										    for (int j=0; j<8; ++j) {
											    if ( (hitmap >> j) & 0x1) {
												    int coloffs = j/4;
												    int rowoffs = j%4;
												    int x = 2*spcol + coloffs;   // x = column
												    int y = 4*sprow + rowoffs;   // y = row
												    h2->Fill(x, y);
                                                    if (phase<=3) bxid--; 
												    //if (x!=0 && y!=0) continue;
												    weight++;

												    
                                                    if (x==icol && y==irow)hvtptwAllPerPix[icol][irow]->Fill(delta, bxid+(1.0/16.)*(15-phase)); 
                                                }    
										    }
									    }
								    }
                                           

								    if (hcnt==2) {
									    unsigned int diff = ( ( (packet[0] & 0x3FFFFFFF) ^ emptyPacket) & ( (packet[1] & 0x3FFFFFFF) ^ emptyPacket) );
									    for (int bit=0; bit<30; bit++) {
										    if ( (diff>>bit) & 0x1 )  bitstats[bit]++;
									    }
								    }
								    if (hcnt>0) stats[hcnt-1]++;
							    }

							    cnt++;
                           }
                        fclose(fp);
					    }
				    }
			    }
			    closedir (dir);

		    } 
		    else {
			    // could not open directory 
			    perror ("");
			    return EXIT_FAILURE;
		    }

	    }
    } //vtploop 
    } //irow
    } //icol
    cout << "found " << pixcnt << " pixels" << endl;
    cout << "stats: " << stats[0] << " " << stats[1] << " " << stats[2] << " " << stats[3] << endl;
    for (int i=0; i<30; i++) printf("%d  ", bitstats[i]);
    printf("\n");


    outputfile->Write();
    return 0;
}

int main(int argc, char *argv[]){
  printf(" argc %d, argv %s \n ", argc, argv[1]);
  if (argc != 2){ 
    cout << " invalid number of arguments, argc = " << argc <<endl;
    return -1;
  }
  char *dirname = argv[1];
  vpx_decode_timewalk_vtploop (dirname);

return 1;
}



