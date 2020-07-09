from Person import *


class Coach(Person):
    __experience = 1

    def __init__(self, name: str, age: int, exp: int):
        Person.__init__(self, name, age)
        __experience = exp

    def get_experience(self) -> int:
        return self.__experience
