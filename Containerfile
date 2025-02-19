FROM docker.io/alpine:latest
WORKDIR /src
COPY . .
RUN apk add --no-cache make g++
RUN make clean build

FROM docker.io/alpine:latest
COPY --from=0 /src/target/app /bin/app
RUN apk add --no-cache libstdc++
CMD ["/bin/app"]
