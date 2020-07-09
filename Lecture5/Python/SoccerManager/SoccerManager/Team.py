from Coach import *
from Keeper import *


class Team:
    __name = "Football FC"
    __coach = Coach("J. Doe", 42, 5)
    __keeper = Keeper("J. Doe", 35, 5, 5, 5, 5)
    __players = []

    def __init__(self, name, coach, keeper, players):
        self.__name = name
        self.__coach = coach
        self.__keeper = keeper
        self.__players = players

    for i in range(10):
        __players.append(Player("J. Doe", 28, 5, 5, 5))

    def get_strength(self) -> float:
        total = 0
        for i in range(10):
            total += self.__players[i].get_strength()
        return total / 10

    def get_motivation(self) -> float:
        total = 0
        for i in range(10):
            total += self.__players[i].get_motivation()
        return total / 10

    def get_name(self) -> str:
        return self.__name

    def get_coach(self) -> Coach:
        return self.__coach

    def get_player(self, num) -> Player:
        return self.__players[num]

    def get_keeper(self) -> Keeper:
        return self.__keeper

    def print_name(self):
        print(self.__name)

    def print_coach(self):
        print(self.__coach.get_name())

    def print_player(self, num):
        print(self.__players[num].get_name())

    def add_goal(self, num):
        self.__players[num].add_goal()
