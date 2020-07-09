from FriendlySoccerMatch import *
import matplotlib.pyplot as plt
import numpy as np

players1 = []
players1.append(Player("K. Dolberg", 18, 6, 9, 10))
players1.append(Player("J. Veltman", 22, 7, 5, 6))
players1.append(Player("M. de Ligt", 24, 9, 4, 7))
players1.append(Player("N. Viergever", 30, 9, 3, 8))
players1.append(Player("M. Dijks", 25, 6, 4, 5))
players1.append(Player("D. van de Beek", 28, 5, 4, 4))
players1.append(Player("L. Schone", 32, 6, 8, 3))
players1.append(Player("H. Ziyech", 27, 3, 7, 6))
players1.append(Player("J. Kluivert", 19, 4, 10, 9))
players1.append(Player("A. Younes", 25, 5, 7, 6))
keeper1 = Keeper("A. Onana", 28, 6, 4, 8, 6)
coach1 = Coach("M. Keizer", 38, 4)

players2 = []
players2.append(Player("P. Onuachu", 19, 8, 7, 7))
players2.append(Player("R. Nissen", 20, 3, 4, 7))
players2.append(Player("K. Hansen", 28, 8, 2, 5))
players2.append(Player("Z. Korcsmar", 27, 6, 4, 7))
players2.append(Player("M. Dal Hende", 29, 7, 4, 6))
players2.append(Player("R. Hassan", 28, 3, 6, 5))
players2.append(Player("J. Drachmann", 30, 5, 5, 4))
players2.append(Player("T. Sparv", 32, 8, 2, 5))
players2.append(Player("J. Poulsen", 33, 4, 9, 7))
players2.append(Player("J. Borring", 31, 5, 6, 6))
keeper2 = Keeper("J. Hansen", 31, 7, 4, 7, 7)
coach2 = Coach("J. Thorup", 45, 4)

team1 = Team("Ajax FC", coach1, keeper1, players1)
team1.print_coach()
team1.print_name()
for i in range(10):
    team1.print_player(i)

team2 = Team("FC Midtjylland", coach2, keeper2, players2)
team2.print_coach()
team2.print_name()
for i in range(10):
    team2.print_player(i)

friendlyMatch = FriendlySoccerMatch()
friendlyMatch.start_game(team1, team2)
friendlyMatch.print_result_text()

friendlyMatch.simulate_games(team1, team2, 2000)

"""
# Data for plotting
t = np.arange(0.0, 2.0, 0.01)
s = 1 + np.sin(2 * np.pi * t)

fig, ax = plt.subplots()
ax.plot(t, s)

ax.set(xlabel='time (s)', ylabel='voltage (mV)',
       title='About as simple as it gets, folks')
ax.grid()

fig.savefig("test.png")
plt.show()

"""
