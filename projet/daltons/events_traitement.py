def point_dans_polygone(clic, polygone):

    x_clic, y_clic = clic
    
    nb_points = len(polygone)
    nb_intersections = 0
    
    for i in range(nb_points):
        x1, y1 = polygone[i]
        x2, y2 = polygone[(i + 1) % nb_points] 
        
        if (y1 > y_clic) != (y2 > y_clic) and x_clic < (x2 - x1) * (y_clic - y1) / (y2 - y1) + x1:
            nb_intersections += 1
    
    return nb_intersections % 2 == 1