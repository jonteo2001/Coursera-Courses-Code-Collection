def get_movies_from_tastedive(string):
    query={} #dict
    #Inserting params when function is called.
    #The Example URL i want:
    #https://tastedive.com/api/similar?q=Black%20Panther&limit=5&type=movie
    query["q"] = string
    query["type"] = "movie"
    query["limit"] = "5"
    baseurl = "https://tastedive.com/api/similar"
    resp = rwc.get(baseurl, params=query)
    print(resp.url)
    print(resp.text)
    return resp.json()

def get_movies_from_tastedive(name):
    parameters = {"q": name, "type": "movies", "limit": 5}
    tastedive_response = rwc.get("https://tastedive.com/api/similar", params=parameters)
    py_data = json.loads(tastedive_response.text)
    return py_data
