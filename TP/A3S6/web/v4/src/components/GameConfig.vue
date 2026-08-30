<template>
  <div class="rectangle2">
    <div class="texte">Configuration</div>
    <div class="config">
      <input type ="text" id="size" name="size" placeholder="nombre de carte" value=""/>
      <input type ="text" id="timer" name="timer" placeholder="temps memorisation" value=""/>
      <input type="text" id="timer4" name="timer4" placeholder="temps jeu" value="">
      <input type="text" id="heart" name="heart" placeholder="nombre de coeur" value=""/>
      <button class="btn" id="submit" onclick="showButtons()">Play</button>
    </div>
  </div>
</template>

<script>
export default {
  name: 'GameConfig',
}


</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

</style>
