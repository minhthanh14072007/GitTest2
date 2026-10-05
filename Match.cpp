#include "Match.h"
#include <iostream>
#include <cstdlib>

Match::Match(Team* H, Team* A) 
    : homeTeam(H), awayTeam(A), homeGoals(0), awayGoals(0), isSimulated(false)
{
}

void Match :: Simulate() {
    if (isSimulated) return; 

    int homeAtt = homeTeam->getTotalAttack();
    int homeDef = homeTeam->getTotalDefend();
    int awayAtt = awayTeam->getTotalAttack();
    int awayDef = awayTeam->getTotalDefend();

    int homeChance = (homeAtt + 5) - awayDef + (rand() % 30);
    int awayChance = awayAtt - homeDef + (rand() % 30);

    homeGoals = homeChance / 15;
    awayGoals = awayChance / 15;

    if (homeGoals < 0) homeGoals = 0;
    if (awayGoals < 0) awayGoals = 0;
    if (homeGoals > 5) homeGoals = 5;
    if (awayGoals > 5) awayGoals = 5;

    if (homeGoals > awayGoals) {
        homeTeam->updateStats(homeGoals, awayGoals, 3);
        awayTeam->updateStats(awayGoals, homeGoals, 0);
    } else if (homeGoals < awayGoals) {
        homeTeam->updateStats(homeGoals, awayGoals, 0);
        awayTeam->updateStats(awayGoals, homeGoals, 3);
    } else {
        homeTeam->updateStats(homeGoals, awayGoals, 1);
        awayTeam->updateStats(awayGoals, homeGoals, 1);
    }

    isSimulated = true; 
}

void Match :: printResult() const{
	std :: cout << "MATCH RESULT" ;
	std :: cout << homeTeam->getName() << "vs" << awayTeam->getName() << std::endl;
	std :: cout << homeGoals <<"-"<< awayGoals << std::endl;
}

