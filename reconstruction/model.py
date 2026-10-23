"""New reconstruction, 2026-10-23. Demo inputs are synthetic, not historical results."""
class Tracker:
    def __init__(self): self.pan,self.tilt=90,90
    def step(self, tl,tr,bl,br):
        values=[tl,tr,bl,br]
        if any(v is None or not 0<=v<=4095 for v in values): return self.pan,self.tilt
        if sum(values)<400: return self.pan,self.tilt
        horizontal=(tr+br)-(tl+bl);vertical=(tl+tr)-(bl+br)
        def delta(error): return 0 if abs(error)<=100 else (1 if error>0 else -1)
        self.pan=max(15,min(165,self.pan+delta(horizontal)))
        self.tilt=max(15,min(165,self.tilt+delta(vertical)))
        return self.pan,self.tilt
def demo():
    c=Tracker();assert c.step(1000,1000,1000,1000)==(90,90)
    for _ in range(200):c.step(500,1500,500,1500)
    assert c.pan==165
    return {'pan':c.pan,'tilt':c.tilt,'mechanical_limits_enforced':True}

if __name__ == "__main__":
    import json
    print(json.dumps(demo(), indent=2))
