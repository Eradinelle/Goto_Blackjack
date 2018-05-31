#include <iostream>
#include <stdlib.h>     // srand, rand
#include <time.h>
#include <windows.h>

using namespace std;

int main()

{

    int result1 = 0, result2 = 0, card1 = 0, card66=0, card77 = 0, card2 = 0, card_count1 = 0, card_count2 = 0, ace11 = 0, Dace11 = 0;
    int budget = 0, min_blind = 0, bet = 0, pot = 0, first_turn = 1, Dfirst_turn = 1;
    char answer, again;

    srand (time(NULL));
    cout << "Enter your budget: $";
    cin >> budget;

    do{
        min_blind = budget * 0.1;
        budget -= min_blind;
        pot += min_blind;
        cout << "The minimum blind is: $" << min_blind << endl;
        do{
            cout << "                                   POT: $" << pot << endl;
            cout << "                                   BUDGET: $" << budget << endl;
            card1 = rand() % 10 + 2;
            if(first_turn == 1){
                card66 = rand() % 10 + 2;
                cout << "Your cards are: "  << card1 <<" and "<<card66 <<endl;
                first_turn --;
                if(card66 == 11){
                    if(11 + card1 > 21){
                        card66 = 1;
                        //in case both cards are aces
                    }
                    else{
                        card66 = 11;
                        ace11 ++;
                    }
                }
            }
            else{
                cout<<"Your card is "<<card1<<endl;
            }
            if(card1 == 11){
                if(11 + result1 > 21){
                    card1 = 1;
                }
                else{
                    card1 = 11;
                    ace11 ++;
                }
            }

            result1 += card1 + card66;
            card66 = 0;
            if(result1 > 21 && ace11 > 0){
                result1 -= 10;
                ace11 --;
            }
            
            cout << "Your current total is: " << result1 << endl;
            
            if(result1 > 21){
                cout << "You're busted!\n" << endl;
                goto stop;
            }
            else if(result1 == 21){
                cout << "Congratulations!\n" << endl;
                Beep(600, 50);
				Beep(600, 50);
				Beep(600, 50);
				Beep(800, 300);
				Beep(600, 50);					Beep(800, 500);
                pot *= 2;
                cout << "You've won: $" << pot;
                budget += pot;
                cout << "You now have: $" << budget;
                goto stop;
            }

            cout << "Would you like to go again?(y) ";
            cin >> answer;
            
            if(answer != 'y'){
                break;
            }
            
            cout << "Place a bet : $";
            cin >> bet;
            
            if(bet > budget){
                bet = budget;
                cout << "You're all in!" << endl;
            }
            
            budget -= bet;
            
            if(budget < 0){
                cout << "YOU'VE LOST ALL YOUR MONEY!" << endl;
                return 0;
            }

            pot += bet;
            card_count1++;
        }while(answer == 'y' && card_count1 < 5);

        cout << endl;
        cout << "Dealer:" << endl;
        
        do{
            card2 = rand() % 10 + 2;
            if(Dfirst_turn == 1){
                card77 = rand() % 10 + 2;
                cout << "Dealer's cards are: "  << card2 <<" and "<<card77 <<endl;
                Dfirst_turn --;
                if(card77 == 11){
                    if(11 + card1 > 21){
                        card77 = 1;
                    }
                    else{
                        card77 = 11;
                        Dace11 ++;
                    }
                }

                result2 = card2 + card77;
                cout<<"Dealer's current total is " <<result2<<endl;
                card77 = 0;
            }
            else{
            	
                cout << "Dealer's card is: "  << card2 << endl;

                if(card2 == 11){
                    if(11 + result2 > 21){
                        card2 = 1;
                    }
                    else{
                        card2 = 11;
                        Dace11 ++;
                    }
                }
                
                result2 += card2;

                if(result2 > 21 && Dace11 > 0){
                    result2 -= 10;
                    Dace11 --;
                }

                cout << "Dealer's current total is: " << result2 << endl;

            }

            if(result2 > 21 && Dace11 == 0){
            	
                cout << "Dealer is busted, You've won!\n" << endl<<endl;               
               	Beep(600, 50);
				Beep(600, 50);
				Beep(600, 50);
				Beep(800, 300);
				Beep(600, 50);
				Beep(800, 500);
                pot *= 2;
                cout << "You've won: $" << pot<<endl<<endl;
                budget += pot;

                cout << "You now have: $" << budget<<endl<<endl;

                goto stop;
            }

            else if(result2 > result1 && result2 <= 21){
            	
                cout << "Dealer has won!\n" << endl<<endl;

                goto stop;
            }

            card_count2++;

        }while(card_count2 < 5 && result2 != 21 && result2 < result1);

        if(result2 < result1){
            pot *= 2;
            
            cout << "You've won: $" << pot <<endl << endl;

            budget += pot;

            cout << "You now have: $" << budget<<endl<<endl;
        }

        else if(result2 == result1){

            cout << "It's a tie!\n" << endl<<endl;

            budget += pot;
        }

        else if(result2 > result1 && result2 <= 21){

            cout << "Dealer has won!\n" << endl<<endl;

        }

stop:

        cout << "Play again? ";
        cin >> again;
        
        if(again == 'y'){
            if(budget == 0){
            	
                cout << "YOU'RE BROKE!" << endl<<endl;

                return 0;
            }
        }

        result1 = 0;
        result2 = 0;
        card_count1 = 0;
        card_count2 = 0;
        ace11 = 0;
        Dace11 = 0;
        pot = 0;
        budget -= pot;
        first_turn = 1;
        Dfirst_turn = 1;

    }while(again == 'y');

    return 0;
}
