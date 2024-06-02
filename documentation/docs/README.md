# Introduction

Trade project

# 👀 Vue d'Ensemble

Le projet consiste à créer un bot de trading révolutionnaire capable d'effectuer des transactions à haute fréquence sur le marché des cryptomonnaies. Le bot doit analyser les indicateurs de marché, s'adapter aux conditions du marché et prendre des décisions de trading en quelques secondes.

## Informations Préliminaires

- **Nom du Binaire** : `trade`
- **Langage** : C
- **Compilation** : Via Makefile avec les règles `re`, `clean`, `fclean` et `doc`.

### Exigences :
- Développer un bot de trading qui maximise les profits et justifie ses stratégies de trading.
- Utiliser des techniques sophistiquées, notamment des indicateurs et des simulateurs de trading en ligne.
- Éviter le surajustement et assurer l'adaptabilité de l'algorithme.
- Utiliser des ensembles de données d'entraînement et un générateur fournis à des fins d'évaluation.

### Grammaire :
- ordre = 'pass' | trade_order
- trade_order = ('achat' | 'vente') devise_devise décimal
