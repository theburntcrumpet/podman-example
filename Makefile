#
# Makefile for test application
# theburntcrumpet
#

# Primary targets
build:
	mkdir -p ./target/
	g++ ./src/main.cpp -o ./target/app

run:
	./target/app

clean:
	rm -Rf target

# Podman targets
podbuild:
	podman build -t "hello-podman:latest" .

podrun:
	podman run hello-podman:latest

podtime:
	time podman run hello-podman:latest


# Podman maintenance
poprune:
	yes | podman system prune