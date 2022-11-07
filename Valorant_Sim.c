
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct player {
	char *name;
	int skill;
	char *rank;
  int baseRankedNum;
  int gameRankedNum;
	char *gun; //not implemented
  bool alive;
  int HP;
	int kills;
	int deaths;
  int assists; //not implemented 
} Player;

typedef struct team {
  char *name;
	Player members[10];
  int playerNum;
	int teamScore;
	int money; //not implemented
} Team;

char *computeDivision(int skill) {
	char *division;
	//division = (char *)malloc(20 * sizeof(char));

	if (skill % 3 == 0) {
		division = "I";
    //player.baseRankedNum += 12;
	} else if (skill % 3 == 1) {
		division = "II";
    //player.baseRankedNum += 24;
	} else if (skill % 3 == 2) {
		division = "III";
    //player.baseRankedNum += 36;
	}
	return division;
}

char *computeRank(int skill) {
	char *rank;
	//rank = (char *)malloc(20 * sizeof(char));
	char *division;
	//division = (char *)malloc(20 * sizeof(char));

	if (skill >= 0 && skill < 15) {
		rank = "Iron ";
    //player->baseRankedNum = 100;
	} else if (skill >= 15 && skill < 35) {
		rank = "Bronze ";
   // player->baseRankedNum = 150;
	} else if (skill >= 35 && skill < 65) {
		rank = "Silver ";
   // player->baseRankedNum = 200;
	} else if (skill >= 65 && skill < 80) {
		rank = "Gold ";
   // player->baseRankedNum = 250;
	} else if (skill >= 80 && skill < 90) {
		rank = "Platinum ";
   // player->baseRankedNum = 300;
	} else if (skill >= 90 && skill < 96) {
		rank = "Diamond ";
   // player->baseRankedNum = 350;
	} else if (skill >= 96 && skill < 99) {
		rank = "Immortal ";
   // player->baseRankedNum = 400;
	} else {
		rank = "Radiant";
   // player->baseRankedNum = 450;
	}

	if (strcmp(rank, "Radiant") != 0) {
		strcpy(division, computeDivision(skill));
    char *finalRank =  (char*)malloc(strlen(rank)+strlen(division)+1);
		strcpy(finalRank, rank);
    strcat(finalRank, division);
		return finalRank;
	} else {
		return rank;
	}
}

int computebaseRankedNum(char *rank){
  int baseRankedNum;
  if (strcmp(rank, "Iron I") == 0){
    baseRankedNum = 100;
  }else if (strcmp(rank, "Iron II") == 0){
    baseRankedNum = 110;
  }else if (strcmp(rank, "Iron III") == 0){
    baseRankedNum = 130;
  }else if (strcmp(rank, "Bronze I") == 0){
    baseRankedNum = 170;
  }else if (strcmp(rank, "Bronze II") == 0){
    baseRankedNum = 210;
  }else if (strcmp(rank, "Bronze III") == 0){
    baseRankedNum = 260;
  }else if (strcmp(rank, "Silver I") == 0){
    baseRankedNum = 320;
  }else if (strcmp(rank, "Silver II") == 0){
    baseRankedNum = 390;
  }else if (strcmp(rank, "Silver III") == 0){
    baseRankedNum = 470;
  }else if (strcmp(rank, "Gold I") == 0){
    baseRankedNum = 560;
  }else if (strcmp(rank, "Gold II") == 0){
    baseRankedNum = 660;
  }else if (strcmp(rank, "Gold III") == 0){
    baseRankedNum = 770;
  }else if (strcmp(rank, "Platinum I") == 0){ 
    baseRankedNum = 890;
  }else if (strcmp(rank, "Platinum II") == 0){
    baseRankedNum = 1020;
  }else if (strcmp(rank, "Platinum III") == 0){
    baseRankedNum = 1160;
  }else if (strcmp(rank, "Diamond I") == 0){
    baseRankedNum = 1310;
  }else if (strcmp(rank, "Diamond II") == 0){
    baseRankedNum = 1470;
  }else if (strcmp(rank, "Diamond III") == 0){
    baseRankedNum = 1640;
  }else if (strcmp(rank, "Immortal I") == 0){
    baseRankedNum = 1900;
  }else if (strcmp(rank, "Immortal II") == 0){
    baseRankedNum = 2100;
  }else if (strcmp(rank, "Immortal III") == 0){
    baseRankedNum = 2400;
  }else if (strcmp(rank, "Radiant") == 0){
    baseRankedNum = 2700;
  }
  return baseRankedNum;
}

int findPro(char *name, int tempNum){
  if (strcmp(name, "SEN TenZ") == 0){
    return 3800;
  }else if(strcmp(name, "SEN Shahzam") == 0){
    return 3300;
  }else if(strcmp(name, "SEN Sick") == 0){
    return 3500;
  }else if(strcmp(name, "Optic yay") == 0){
    return 3700;
  }else if(strcmp(name, "Optic Marved") == 0){
    return 3600;
  }else if(strcmp(name, "Optic Victor") == 0){
    return 3600;
  }else if(strcmp(name, "TSM Wardell") == 0){
    return 3500;
  }else if(strcmp(name, "TSM Subroza") == 0){
    return 3300;
  }else if(strcmp(name, "DanielTTdog") == 0){
    return 80;
  }else if(strcmp(name, "Tarik") == 0){
    return 3400;
  }else if(strcmp(name, "ACE cNed") == 0){
    return 3700;
  }else if(strcmp(name, "SEN Dapr") == 0){
    return 3100;
  }else if(strcmp(name, "SEN Kanpeki") == 0){
    return 3200;
  }else{
    return tempNum;
  }
}

Player createPlayer(char *name, int skill) {
	Player player;
	// player = (Player*) malloc(sizeof(Player));
	//player.rank = (char *)malloc(20 * sizeof(char));
  //player.name = (char *)malloc(20 * sizeof(char));
	strcpy(player.name, name);
	player.skill = skill;
	strcpy(player.rank, computeRank(skill));
  player.baseRankedNum = computebaseRankedNum(player.rank);
  //strcpy(player.rank, "Iron I");
	return player;
}

Player manualCreate(char *name, char *rank){
  Player player;
	// player = (Player*) malloc(sizeof(Player));
	player.rank = (char *)malloc(20 * sizeof(char));
  player.name = (char *)malloc(20 * sizeof(char));
	strcpy(player.name, name);
	strcpy(player.rank, rank);
  player.baseRankedNum = computebaseRankedNum(player.rank);
  player.baseRankedNum = findPro(player.name, player.baseRankedNum);
  //strcpy(player.rank, "Iron I");
	return player;
}

char *choppy( char *s ){
    char *n = (char*)malloc(100*sizeof(char) );
    strcpy(n,s);
    n[strlen(n)-1]='\0';
    return n;
}

Team createTeam(char *name, int playerNum){
  Team team;
  team.name = (char*)malloc(20 * sizeof(char));
  team.playerNum = playerNum;
  strcpy(team.name, name);
  return team;
}

int computeChance(int challenger, int opponent){
  float chance = ((challenger*1.0)/((opponent+challenger)*1.0))*1000;
  return (int)chance;
}

void battle(Player *player, Team *oppTeam){
  int damage;
  int trueDamage;
  //int HP;
  int chooseOpponent = rand ()%(oppTeam->playerNum);
  while (oppTeam->members[chooseOpponent].alive == false){
    if (chooseOpponent == (oppTeam->playerNum)-1){
      chooseOpponent = 0;
    }else{
      chooseOpponent++; 
    }
  }
  int chanceofWin = computeChance(player->gameRankedNum, oppTeam->members[chooseOpponent].gameRankedNum);
  //printf("%s\n", player.name);
  printf("%s vs %s\nChance to win: %d\n", player->name, oppTeam->members[chooseOpponent].name, chanceofWin);
  int chance = rand()%1000;
  if (chance < chanceofWin){
    printf("%s has won the duel.\n", player->name);
    oppTeam->members[chooseOpponent].alive = false;
    player->kills++;
    oppTeam->members[chooseOpponent].deaths++;

    int damageChance = (int)((((oppTeam->members[chooseOpponent].gameRankedNum)*3.0) / (((oppTeam->members[chooseOpponent].gameRankedNum)*3.0)+player->gameRankedNum*1.0))*1000);
  
    if (rand()%1000 < damageChance){
      damage = rand()%(oppTeam->members[chooseOpponent].gameRankedNum);
      if (player->gameRankedNum - damage < (player->gameRankedNum) /5){
        player->gameRankedNum = player->gameRankedNum/5; //1/5 as weak as original is the lower limit
        damage = (player->gameRankedNum/5)*4;
      }else{
        player->gameRankedNum = player->gameRankedNum - damage;
      } 

      trueDamage = (player->HP - ((player->gameRankedNum)*1.0/(player->baseRankedNum)*1.0)*150)+1;
      player->HP = ((player->gameRankedNum)*1.0/(player->baseRankedNum)*1.0)*150;
 
      
      printf("%s did %d damage to %s\n", oppTeam->members[chooseOpponent].name, trueDamage, player->name);
    }else{
      printf("%s did no damage\n", oppTeam->members[chooseOpponent].name);
    }
    
    //player did no damage
    printf("%s's HP: %d\n", player->name, player->HP);
  }else{
    printf("%s has won the duel.\n", oppTeam->members[chooseOpponent].name);
    
     player->alive = false;
    oppTeam->members[chooseOpponent].kills++;
    player-> deaths++;

    int damageChance = (int)((((player->gameRankedNum)*3.0) / (((player->gameRankedNum)*3.0)+oppTeam->members[chooseOpponent].gameRankedNum*1.0))*1000);

    if (rand()%1000 < damageChance){
      damage = rand()%(player->gameRankedNum);
      if (oppTeam->members[chooseOpponent].gameRankedNum - damage < (oppTeam->members[chooseOpponent].gameRankedNum) /5){
        oppTeam->members[chooseOpponent].gameRankedNum = oppTeam->members[chooseOpponent].gameRankedNum/5; //1/5 as weak as original is the lower limit
        damage = ((oppTeam->members[chooseOpponent].gameRankedNum)/5.0)*4;
      }else{
        oppTeam->members[chooseOpponent].gameRankedNum = oppTeam->members[chooseOpponent].gameRankedNum - damage;
      } 

      trueDamage = (oppTeam->members[chooseOpponent].HP - ((oppTeam->members[chooseOpponent].gameRankedNum)*1.0/(oppTeam->members[chooseOpponent].baseRankedNum)*1.0)*150) +1;
      oppTeam->members[chooseOpponent].HP = ((oppTeam->members[chooseOpponent].gameRankedNum)*1.0/(oppTeam->members[chooseOpponent].baseRankedNum)*1.0)*150;
      
      printf("%s did %d damage to %s\n", player->name, trueDamage, oppTeam->members[chooseOpponent].name);
    }else{
     printf("%s did no damage\n", player->name);
    }
    printf("%s's HP: %d\n", oppTeam->members[chooseOpponent].name, oppTeam->members[chooseOpponent].HP);
    //player did no damage
  }
}

bool checkAlive (Team team){
  for(int i = 0; i< team.playerNum; i++){
    if (team.members[i].alive){
      return true;
    }
  }
  return false;
}

void printTeams(Team team1, Team team2){
  if (!checkAlive(team1)){
    printf("%s ELIMINATED\n", team1.name);
  }
  if(!checkAlive(team2)){
    printf("%s ELIMINATED\n", team2.name);
  }
  
  if(checkAlive(team1)){
      printf("Team 1 %s:\n", team1.name);
    for (int i = 0; i < team1.playerNum;i ++){
      if (team1.members[i].alive== true){
        printf("Name: %s\nRank: %s\nKills: %d\nDeaths: %d\n\n\n", team1.members[i].name, team1.members[i].rank, team1.members[i].kills, team1.members[i].deaths);
      }
    }
  }

  if (checkAlive(team2)){
    printf("Team 2 %s:\n", team2.name);
    for (int i = 0; i < team2.playerNum;i ++){
      if (team2.members[i].alive == true){
        printf("Name: %s\nRank: %s\nKills: %d\nDeaths: %d\n\n\n", team2.members[i].name, team2.members[i].rank, team2.members[i].kills, team2.members[i].deaths);
      }
    }
  }
}

void scaleRank(Team *team, int playerNum){
  float scale = 1;
  float increase = playerNum * 0.8;
  scale += increase;
  
  for (int i = 0; i < playerNum; i++){
    team->members[i].baseRankedNum *= scale;
  }
}

void initialize(Team *team1, Team *team2){
  team1->teamScore = 0;
  team1->money = 0;
  team2->teamScore = 0;
  team2->money = 0;
  for (int i = 0; i < team1->playerNum; i++){
    team1->money = 1;
    team1->members[i].deaths = 0;
    team1->members[i].kills = 0;
  }
  for (int i = 0; i < team2->playerNum; i++){
    team2->money = 1;
    team2->members[i].deaths = 0;
    team2->members[i].kills = 0;
  }
  scaleRank(team1, team1->playerNum);
  scaleRank(team2, team2->playerNum);
}

void printScoreBoard(Team team1, Team team2){
  printf("\n");
  printf("%s\n", team1.name);
  printf("Name\t\t\tKills\t\tDeaths\t\tRank\n");
  for (int i = 0; i < team1.playerNum; i++){
    printf("%s", team1.members[i].name);
    for (int q = 0; q < 4+12-strlen(team1.members[i].name); q++){
      printf(" ");
    }
    printf("%d", team1.members[i].kills);
    if (team1.members[i].kills >=10){
      printf("          ");
    }else{
      printf("           ");
    }
    printf("%d", team1.members[i].deaths);
    if (team1.members[i].deaths >=10){
      printf("          ");
    }else{
      printf("           ");
    }
    printf("%s", team1.members[i].rank);
    printf("\n");
  }
    /*printf("%s\t\t\t%d\t\t%d\t\t%s\n",team1.members[i].name, team1.members[i].kills, team1.members[i].deaths, team1.members[i].rank);
  }*/
  printf("\n");
  printf("%s\n", team2.name);
  printf("Name\t\t\tKills\t\tDeaths\t\tRank\n");
  for (int i = 0; i < team2.playerNum; i++){
    printf("%s", team2.members[i].name);
    for (int q = 0; q < 4+12-strlen(team2.members[i].name); q++){
      printf(" ");
    }
    printf("%d", team2.members[i].kills);
    if (team2.members[i].kills >=10){
      printf("          ");
    }else{
      printf("           "); 
    }
    printf("%d", team2.members[i].deaths);
    if (team2.members[i].deaths >=10){
      printf("          ");
    }else{
      printf("           "); 
    }
    printf("%s", team2.members[i].rank);
    printf("\n");
  }
  /*for (int i = 0; i < 5; i++){
    printf("%s\t\t\t%d\t\t%d\t\t%s\n",team2.members[i].name, team2.members[i].kills, team2.members[i].deaths, team2.members[i].rank);
  }*/
  
}

void simulate(Team *team1, Team *team2){
  initialize(team1, team2);
  char *userin;
  userin = (char*)malloc(10*sizeof(char));
  
  do{
    printf("Enter 1 to begin.\n");
    scanf("%s", userin);
  }while (strcmp(userin, "1") != 0);

  int roundNumber = 1;
  while (!((team1->teamScore >= 13 && abs(team1->teamScore - team2->teamScore) >= 2) || (team2->teamScore >= 13 && abs(team1->teamScore - team2->teamScore) >= 2))){
    for (int i = 0; i < team1->playerNum; i++){
      team1->members[i].alive = true;
      team1->members[i].gameRankedNum = team1->members[i].baseRankedNum;
      team1->members[i].HP = 150;
    }
    for (int i = 0; i < team2->playerNum; i++){
      team2->members[i].alive = true;
      team2->members[i].gameRankedNum = team2->members[i].baseRankedNum;
      team2->members[i].HP = 150;
    }
    
    printf("\nROUND %d:\n", roundNumber);
    printf("\n----------------------------------------------------------\n");

    while (checkAlive(*team1) && checkAlive(*team2)){
      int teamTurn = rand ()%2;
      
      if(teamTurn == 0){
        int playerTurn = rand ()%(team1->playerNum);
        
        while (team1->members[playerTurn].alive == false){
          if (playerTurn == (team1->playerNum)-1){
            playerTurn = 0;
          }else{
           playerTurn++; 
          }
        }
        battle(&(team1->members[playerTurn]), team2);
        
      }else{

        int playerTurn = rand ()%(team2->playerNum);
        
         while (team2->members[playerTurn].alive == false){
          if (playerTurn == (team2->playerNum)-1){
            playerTurn = 0;
          }else{
           playerTurn++; 
          }
        }
        battle(&(team2->members[playerTurn]), team1);
        
      }
      
      /*do{
        printf("Enter 1 to continue.\n");
        scanf("%s", userin);
      }while (strcmp(userin, "1") != 0);*/
      printf("\n----------------------------------------------------------\n");
      //printTeams(*team1, *team2);
    }
    if (checkAlive(*team1) == false){
      team2->teamScore ++;
    }else{
      team1->teamScore++;
    }
     printf("%s %d - %d %s\n\n", team1->name, team1->teamScore, team2->teamScore, team2->name);
    roundNumber++;
    
    do{
      printf("Press 1 to continue.\n");
      scanf("%s", userin);
    }while (strcmp(userin, "1") != 0);

    printf("\n----------------------------------------------------------");
  }
  printf("\n----------------------------------------------------------\n");
  printf("MATCH OVER\n");
  if (team1->teamScore == 13){
    printf("%s's VICTORY\t%d - %d\n", team1->name, team1->teamScore, team2-> teamScore);
  }else{
    printf("%s's VICTORY\t%d - %d\n", team2->name, team2->teamScore, team1->teamScore);
  }
  printScoreBoard(*team1, *team2);
}

int main(void) {
  srand(time(NULL));
	printf("Welcome to Valorant simulator!\n");
	printf("\n");

  Team team1 = createTeam("Team ONE",1);
  Team team2 = createTeam("Team TWO",1);

  team1.members[0] = manualCreate("iiSaltManii", "Bronze II");
  //team1.members[1] = manualCreate("Bobbazor", "Platinum I");
  //team1.members[2] = manualCreate("DanielTTdog2", "Iron I");
  //team1.members[3] = manualCreate("DanielTTdog3", "Iron I");
  //team1.members[4] = manualCreate("DanielTTdog4", "Iron I");


  team2.members[0] = manualCreate("DanielTTdog", "Iron I");
  //team2.members[1] = manualCreate("random radiant1", "R ant");
  //team2.members[2] = manualCreate("a vegetable", "Immortal III");
  //team2.members[3] = manualCreate("Corn", "Immortal II");
  
  /*FILE* ptr = fopen("usernames.txt", "r");
  int i = 1;
  char line[100]; 
  
  Team team1 = createTeam("Sentinels",5);
  Team team2 = createTeam("TSM", 5);
  
    while (fscanf(ptr, "%s ", line) == 1 && i <= 10){
    //choppy(line);
    Player player = createPlayer(line, rand()%100);

    if (i <=5){
      team1.members[i-1] = player;
    }else{
      team2.members[i-6] = player;
    }
    i++;
  }*/

  printf("Team 1 %s:\n", team1.name);
  for (int i = 0; i < team1.playerNum;i ++){
    printf("Name: %s\nRank: %s\nbaseRankedNum: %d\n\n", team1.members[i].name, team1.members[i].rank, team1.members[i].baseRankedNum);
  }
  printf("Team 2 %s:\n", team2.name);
  for (int i = 0; i < team2.playerNum;i ++){
    printf("Name: %s\nRank: %s\nbaseRankedNum: %d\n\n", team2.members[i].name, team2.members[i].rank, team2.members[i].baseRankedNum);
  }

  simulate(&team1, &team2);
	return 0;
}
