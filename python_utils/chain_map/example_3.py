import string

greeting = "Hey $name, welcome to $place!"
template = string.Template(greeting)

template.substitute({"name": "Jane", "place": "the World"})  # 'Hey Jane, welcome to the World!'

template.substitute({"name": "Jane", "place": "the World"}, place="the House")  # 'Hey Jane, welcome to Real Python!'
