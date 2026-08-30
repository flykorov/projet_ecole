# def milieu(points):
#     return sum(i[0] for i in points)/len(points),sum(i[0] for i in points)/len(points)


def milieu(forme):
    x = 0
    y = 0
    
    for i in forme:
        x += i[0]
        y += i[1]

    nb = len(forme)
    m_x = x / nb
    m_y = y /nb

    return (m_x, m_y)

