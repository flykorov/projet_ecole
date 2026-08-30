from random import randint,shuffle
def n_mdp() -> str:
    

    mdp = randint(0,999)
    if mdp < 100:
        if mdp < 10:
            mdp = "00"+str(mdp)
        else:
            mdp = "0"+str(mdp)
    else:
        mdp = str(mdp)
    return mdp

class tout():
    def __init__(self) -> None:
        self.mdp = n_mdp()
        self.ordre = [0,1,2]
        self.vase_ordre = [100,350,600]
        shuffle(self.vase_ordre)
        shuffle(self.ordre)

    def get_mdp(self) -> str:
        return self.mdp

    def get_ordre(self) -> list:
        return self.ordre
    
    def get_vaseordre(self)-> list:
        return self.vase_ordre

