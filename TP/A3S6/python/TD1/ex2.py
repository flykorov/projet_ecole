def parse_url(url):
	scheme, suivant = url.split('://')
	host, suivant = suivant.split('/', 1)
	if ':' in host:
		host, port = host.split(':')
		port = int(port)
	else:
		port = None

	if suivant == '':
		if port == None:
		    return {'scheme':scheme, 'host':host, 'path': '/'}
		return {'scheme':scheme, 'host':host, 'port':port, 'path': '/'}

	path, suivant = suivant.split('?')
	path = '/' + path

	suiv = suivant.split('&')

	# oops = suiv.split('=')

	query = {k:v for (k, v) in map(lambda x: x.split('='), suiv)}

	# port = None
	# return {'scheme':scheme, 'host':host, 'port':port, 'path': path, 'query': query}
	if port == None: 
		return {'scheme': scheme, 'host': host, 'path': path, 'query': query}
	return {'scheme': scheme, 'host': host, 'port': port, 'path': path, 'query': query}

a = 'http://www.domain.com:80/path/to/file?key1=value1&key2=value2'
b = parse_url(a)
print(b)