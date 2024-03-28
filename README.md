# **FdF**

## :speech_balloon: **About**
Fdf is a computer graphics project that uses  the school graphics library, MiniLibX,  to represent a landscape as a 3D object in which all surfaces are outlined in lines. 
The program reads a file that contains the coordinates of the landscape and uses an algorithm to connect the dots with lines, representing it in isometric projection.
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
```


<table align=center>
	<tbody>
		<tr>
			<td><image src="img/"></td>
			<td><image src="img/"></td>
		</tr>
	</tbody>
</table>

## :link: **Compilation**
To compile the program you should run `make`.

This rule will generate an executable file named `fdf`. To launch the executable you should follow this syntax:

```sh
$ ./fdf/maps/42.fdf
```
Or, if you have your own scenes you want to render:

```sh
$ ./fdf ./path_to_map/map_name.rt
```
