# **FdF**

## :speech_balloon: **About**
Fdf is a computer graphics project that uses  the school graphics library, MiniLibX,  to represent a landscape as a 3D object in which all surfaces are outlined in lines. 
The project is coded in C, utilizing the mlx library.

## 🙋‍♀️ **Authorship**
- [Rita Marques](https://github.com/rimarque)

## :inbox_tray: **Cloning the repository**

```shell
git clone git@github.com:rimarque/FDF.git 
```

## 💎 **Features**
```
- Map file parser
- Algoritm to connect the points (self-developed)
- Algorithm to draw a line between two points (DDA)
- Display of a landscape in isometric projection
```


<table align=center>
	<tbody>
		<tr>
			<td><image src="img/42.png"></td>
			<td><image src="img/t1.png"></td>
		</tr>
	</tbody>
</table>

## :link: **Compilation**
To compile the program you should run `make`.

This rule will generate an executable file named `fdf`. To launch the executable you should follow this syntax:

```sh
$ ./fdf ./maps/42.fdf
```
Or, if you have your own maps you want to render:

```sh
$ ./fdf ./path_to_map/map_name.fdf
```
