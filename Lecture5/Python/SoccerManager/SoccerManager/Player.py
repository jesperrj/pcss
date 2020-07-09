import random

from Person import *


class Player(Person):
    __strength = 1
    __shots = 1
    __motivation = 1
    __goals = 0

    def __init__(self, name, age, st, sh, mo):
        Person.__init__(self, name, age)
        self.__strength = st
        self.__shots = sh
        self.__motivation = mo

    def print_info(self):
        print("PLAYER INFO:")
        print("Name: "+self.get_name())
        print("Age: " + str(self.get_age()))
        print("Stats: ["+str(self.__strength)+","+str(self.__shots)+","+str(self.__motivation)+"]")

    def get_goals(self) -> int:
        return self.__goals

    def add_goal(self):
        self.__goals += 1

    def shoots_on_goal(self) -> int:
        self.__shots = max(1, min(10, self.__shots+random.randint(-1, 1)))
        ret = max(1, min(10, self.__shots+random.randint(-1, 1)))
        return ret

    def get_strength(self) -> int:
        return self.__strength

    def get_motivation(self) -> int:
        return self.__motivation

