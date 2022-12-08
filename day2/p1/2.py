score = 0
f = open("input.txt", "r")

for line in f:
    rounds = line
    print(rounds)
    print(score)

    if rounds == "A X\n":
        score = 3 + 1 + score
    elif rounds == "A Y\n":
        score = 6 + 2 + score
    elif rounds == "A Z\n":
        score = 0+3+score
    elif rounds == "B X\n":
        score = 0 + 1 + score
    elif rounds == "B Y\n":
        score = 3 + 2 + score
    elif rounds == "B Z\n":
        score = 6 + 3 + score
    elif rounds == "C X\n":
        score = 6 + 1 + score
    elif rounds == "C Y\n":
        score = 0 + 2 + score
    elif rounds == "C Z\n":
        score = 3 + 3 + score
	    
    print(score)