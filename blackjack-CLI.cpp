#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <cstdlib>

int main()
{
		char play;
		int totalp {0};
		int totald {0};
		int deck;
		int aux {0};
		int bet;
		int coininit {10};	
		char c;
		std::string username = getenv("USERNAME");

		srand (time(NULL));
		system( "clear || CLS" );

		while( coininit > 0 ){
				std::cout << "\u2660\u2663\e[31;1m\u2665\u2666\e[m Tblack-Jack \u2660\u2663\e[31;1m\u2665\u2666\e[m"  << "\n";
				std::cout << '\n' << username << " VOCÊ TEM " << coininit << " COINS." << '\n';
				std::cout << "\nQUAL SUA APOSTA?"  << '\n';
				std::cin >> bet;

				if( bet > coininit ){
						while( bet > coininit){
								std::cout << "COINS INSUFICIENTES."  << '\n';
								std::cout << "QUAL SUA APOSTA?" << '\n';
								std::cin >> bet;
						}
				}
				else if( bet == 0 ){
						while( bet < 1){
								std::cout << "A APOSTA NÃO PODE SER < 1!"  << '\n';
								std::cout << "QUAL SUA APOSTA?" << '\n';
								std::cin >> bet;
						}
				}
				while( totalp < 20 + 1){		
						std::cout << "\n[1]PEDIR [0]PARAR: ";	  
						std::cin >> play;

						if( play == '1' ){
								deck = rand() % 10 + 1;
								aux = deck;
								totalp += aux;	
								std::cout << "CARD" << "|" << deck << "|";
								//std::cout << " - TOTAL " << totalp;
						}
						else if( play == '0' ){	
								aux = 0;
								std::cout << "\nAÇÂO DO DEALER."  << '\n';

								for (int i = 1; totald <= 20 + 1; i++) {
										deck = rand() % 10 + 1;
										aux = deck;
										totald += aux;	
										std::cout << "CARD" << "|" << deck << "|" << '\n'  ;
										//std::cout << " - TOTAL " << totald;	

										if(totald >= 21 || totald > totalp ){
												break;
										}
								}
						}
						else{
								std::cout << "OPÇÂO INVALIDA."  << '\n';
								std::cout << "O JOGO FOI FECHADO.\n"  << '\n';
								return 0;
						}
						if(totald >= 21 || totald > totalp ){
								break;
						}
				}
				std::cout << '\n';
				std::cout << "\nPLAYER: " << totalp << '\n';
				if(totalp < 21){
						std::cout << "DEALER: " << totald << '\n';
				}

				if(( totalp > 21 || totald > totalp ) && (totald < 21)){
						coininit -= bet;
						std::cout << "\n\e[5m\u2660\u2663\u2665\u2666 A BANCA VENCEU \u2660\u2663\u2665\u2666" << "\e[m\n";	
				}
				else if( totalp == 21){
						coininit += bet;
						std::cout << "\n\e[5m\u2660\u2663\u2665\u2666 BLACK JACK! \u2660\u2663\u2665\u2666" << "\e[m\n";	
						std::cout << '\n';
				}
				else if( totald > 21 || totalp > totald ){
						coininit += bet;						
						std::cout << "\n\e[5m\u2660\u2663\u2665\u2666 VOCÊ GANHOU \u2660\u2663\u2665\u2666\e[m"  << '\n';
				}
				else if(totald == 21){
						std::cout << "\n\e[5m\u2660\u2663\u2665\u2666 BLACK JACK PARA A BANCA! \u2660\u2663\u2665\u2666" << "\e[m\n";	
				}

				totald = 0;
				totalp = 0;

				if(coininit > 0){
						std::cout << "\nEMBARALHANDO.\e[5m.\e[m\e[5m.\e[m"  << '\n';	
						std::this_thread::sleep_for( std::chrono::seconds(10));
						system("clear");
				}
		}

		while( c != 'y' || c != 'n' || c != 'Y' || c != 'N'){
				std::cout << "\nG A M E  O V E R"  << '\n';
				std::cout << "VOCÊ GOSTARIA DE TENTA DE NOVO? Y/N"  << '\n';
				std::cin >> c;

				if( c == 'y' || c == 'Y' ){
						return main();
				}
				else if( c == 'n' || c == 'N'){
						return 0;
				}
		}
}

