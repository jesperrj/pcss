from Team import *


class FriendlySoccerMatch:
    __nameHomeTeam = "A"
    __nameGuestTeam = "B"
    __pointsHome = 0
    __pointsGuest = 0

    def get_home_team(self):
        return self.__nameHomeTeam

    def get_guest_team(self):
        return self.__nameGuestTeam

    def get_home_points(self):
        return self.__pointsHome

    def get_guest_points(self):
        return self.__pointsGuest

    def print_result_text(self):
        print("The friendly game ends with \n\n" + self.__nameHomeTeam + " - " + self.__nameGuestTeam
              + " " + str(self.__pointsHome) + ":" + str(self.__pointsGuest))

    def start_game(self, t1: Team, t2: Team):
        self.__nameHomeTeam = t1.get_name()
        self.__nameGuestTeam = t2.get_name()

        gameRuns = True
        gameDuration = 90 + random.randint(0, 4)
        time = 1

        while gameRuns:
            nextAction = random.randint(0, 14) + 1
            if (time + nextAction) > gameDuration or time > gameDuration:
                # gameRuns = False
                break

            time += nextAction

            strength1 = float(t1.get_strength()) / 2.0 + \
                ((float(t1.get_strength()) / 2.0) * (float(t1.get_motivation()) / 10.0))
            strength2 = float(t2.get_strength()) / 2.0 + \
                ((float(t2.get_strength()) / 2.0) * (float(t2.get_motivation()) / 10.0))

            deviation = random.randint(0, 1)
            if strength1 > t1.get_coach().get_experience():
                deviation = -deviation
            strength1 = max(1, min(10, strength1 + deviation))

            deviation = random.randint(0, 1)
            if strength2 > t2.get_coach().get_experience():
                deviation = -deviation
            strength2 = max(1, min(10, strength2 + deviation))

            shooter = random.randint(0, 9)

            if random.randint(int(-strength1), int(strength2)) <= 0:
                ptmp = t1.get_player(shooter)   # type: Player
                ktmp = t2.get_keeper()          # type: Keeper
                shot = ptmp.shoots_on_goal()
                if ktmp.save_shot(shot):
                    goal = False
                else:
                    goal = True

                print("\n" + str(time) + ".Minute:\n Chance for " + t1.get_name() + "...\n "
                      + ptmp.get_name() + " shoots")

                if goal:
                    self.__pointsHome += 1
                    t1.add_goal(shooter)

                    print(" GOAL!!! " + str(self.__pointsHome) + ":" + str(self.__pointsGuest) + " " +
                          ptmp.get_name() + "(" + str(t1.get_player(shooter).get_goals()) + ")")
                else:
                    print(" " + t2.get_keeper().get_name() + " saves brilliantly.")
            else:
                ptmp = t2.get_player(shooter)   # type: Player
                ktmp = t1.get_keeper()          # type: Keeper
                shot = ptmp.shoots_on_goal()
                if ktmp.save_shot(shot):
                    goal = False
                else:
                    goal = True

                print("\n" + str(time) + ".Minute:\n Chance for " + t2.get_name() + "...\n "
                      + ptmp.get_name() + " shoots")

                if goal:
                    self.__pointsGuest += 1
                    t2.add_goal(shooter)

                    print(" GOAL!!! " + str(self.__pointsHome) + ":" + str(self.__pointsGuest) + " " +
                          ptmp.get_name() + "(" + str(t2.get_player(shooter).get_goals()) + ")")
                else:
                    print(" " + t1.get_keeper().get_name() + " saves brilliantly.")
