<div align="center">

# Trade

**Un bot de trading en C, entièrement documenté avec Doxygen.**

<img alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/> <img alt="Make" src="https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=gnu&logoColor=white"/> <img alt="Doxygen" src="https://img.shields.io/badge/Doxygen-2C4AA8?style=for-the-badge&logo=doxygen&logoColor=white"/> <img alt="GitHub Actions" src="https://img.shields.io/badge/GitHub%20Actions-2088FF?style=for-the-badge&logo=githubactions&logoColor=white"/>

<sub>Projet solo · 2024</sub>

</div>

<br/>

<p align="center"><img src=".github/assets/trade-doc-main.png" alt="Trade" width="820"/></p>

## Le projet en quelques mots

Un bot qui dialogue avec un moteur de trading par l'entrée et la sortie standard. À chaque bougie (*candle*), il décide d'acheter, de vendre ou de ne rien faire, en tenant compte des frais. Le code est documenté fonction par fonction, et la doc HTML est générée avec Doxygen.

## Ce que ça fait

- Lecture des paramètres du moteur : capital, frais, format des bougies…
- Lecture du flux de bougies (open, high, low, close, volume)
- Décision `buy` / `sell` / `no_moves` à chaque tour
- Documentation Doxygen complète dans [`documentation/`](documentation)

## Lancer le projet

```bash
make
```
