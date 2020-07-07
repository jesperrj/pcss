from Player import *


class Keeper(Player):
    __reaction = 1

    def __init__(self, name, age, st, sh, mo, re):
        Player.__init__(self, name, age, st, sh, mo)
        self.__reaction = re

    def save_shot(self, shot):
        r = random.randint(-1, 1)
        ret = max(1, min(10, self.__reaction+r))

        if ret >= shot:
            return True
        else:
            return False
