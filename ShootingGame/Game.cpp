#include"SDL_image.h"
#include"Game.h"
#include"Actor.h"
#include"Drawer.h"
#include"InputSystem.h"
#include"KeyboardState.h"
#include"PhysWorld.h"
#include<vector>
#include <SDL_image.h>

Game::Game()
	:mWindow(nullptr)
	, mRenderer(nullptr)
	, mGameState(EGameplay)
	, mTickCount(0)
	, mDrawers([](const Drawer* l, const Drawer* r) {return l->GetOrder() < r->GetOrder(); })
	, mPhysWorld(nullptr)
{

}

bool Game::Initialize() {
	// SDL‰Šú‰»
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	// SDL Windowì¬
	mWindow = SDL_CreateWindow(
		"ShootingGame!", // Window title
		128,	// Top left x-coordinate of window
		128,	// Top left y-coordinate of window
		1024,	// Width of window
		768,	// Height of window
		0		// Flags (0 for no flags set)
	);

	if (!mWindow)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	// SDL rendererì¬
	mRenderer = SDL_CreateRenderer(
		mWindow, // Window to create renderer for
		-1,		 // Usually -1
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	//SDL_IMG ‰Šú‰»
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
		return false;
	}

	mInputSystem = new InputSystem();
	if (!mInputSystem->Initialize()) {
		SDL_Log("Failed to initaialize input system");
		return false;
	}

	mPhysWorld = new PhysWorld(this);
	if (!mPhysWorld) {
		SDL_Log("Failed to initialize PhysWorld");
		return false;
	}


	LoadData();

	mTickCount = SDL_GetTicks();

	return true;
}

void Game::RunLoop()
{
	while (mGameState != EQuit)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::Shutdown()
{
	UnloadData();

	mInputSystem->Shutdown();
	delete mInputSystem;

	delete mPhysWorld;

	IMG_Quit();
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::ProcessInput() {

	mInputSystem->PrepareUpdate();

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			// If we get an SDL_QUIT event, end loop
		case SDL_QUIT:
			mGameState = EQuit;
			break;
		}
	}

	mInputSystem->Update();

	// Get state of keyboard
	const InputState& state = mInputSystem->GetState();
	// If escape is pressed, also end loop
	if (state.Keyboard.GetKeyState(SDL_SCANCODE_ESCAPE) == ButtonState::EGetUp)
	{
		mGameState = EQuit;
	}
	
	mIsUpdatingActors = true;
	for (auto actor : mActors) {
		actor->ProcessInput(state);
	}
	mIsUpdatingActors = false;
}

void Game::UpdateGame() {
	// Wait until 16ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTickCount + 16))
		;

	// Delta time is the difference in ticks from last frame
	// (converted to seconds)
	float deltaTime = (SDL_GetTicks() - mTickCount) / 1000.0f;

	// Clamp maximum delta time value
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}
	mTickCount = SDL_GetTicks();


	//Update Actors
	mIsUpdatingActors = true;
	for (auto actor : mActors) {
		actor->Update(deltaTime);
	}

	for (auto actor : mActors) {
		actor->LastUpdate(deltaTime);
	}

	mPhysWorld->TestPairwise(nullptr);

	mIsUpdatingActors = false;

	//’Ç‰Á‘Ò‚¿‚É‚µ‚Ä‚¢‚½Actor‚ğ’Ç‰Á
	for (auto pend : mPendingActors) {
		mActors.emplace_back(pend);
	}
	mPendingActors.clear();

	//Deadó‘Ô‚ÌActor‚ğíœ
	std::vector<Actor*> deadActors;
	for (auto actor : mActors) {
		if (actor->GetState() == Actor::EDead) {
			deadActors.emplace_back(actor);
		}
	}
	for (auto dead : deadActors) {
		delete dead;
	}
}

void Game::GenerateOutput() {
	// Set draw color
	SDL_SetRenderDrawColor(
		mRenderer,
		0,	// R
		0,	// G 
		0,	// B
		255		// A
	);

	// Clear back buffer
	SDL_RenderClear(mRenderer);

	// Actor•`‰æ
	for (auto drawer : mDrawers) {
		if(drawer->GetActor()->GetState() == Actor::EActive)
			drawer->Draw(mRenderer);
	}

	// Swap front buffer and back buffer
	SDL_RenderPresent(mRenderer);
}

void Game::AddActor(Actor* actor)
{
	if (mIsUpdatingActors)
	{
		mPendingActors.emplace_back(actor);
	}
	else
	{
		mActors.emplace_back(actor);
	}
}

void Game::RemoveActor(Actor* actor) {
	// pending‚Ì•û‚É“ü‚Á‚Ä‚¢‚½
	auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end()) {
		std::iter_swap(iter, mPendingActors.end() - 1);
		mPendingActors.pop_back();
	}

	//mActors‚Ì•û‚É“ü‚Á‚Ä‚¢‚½
	iter = std::find(mActors.begin(), mActors.end(), actor);
	if (iter != mActors.end())
	{
		std::iter_swap(iter, mActors.end() - 1);
		mActors.pop_back();
	}
}

void Game::AddDrawer(Drawer* drawer) {
	mDrawers.insert(drawer);
}

void Game::RemoveDrawer(Drawer* drawer) {
	//auto count = mDrawers.count(drawer);
	//SDL_Log("%d", count);
	auto iterp = mDrawers.equal_range(drawer);
	for (auto iter = iterp.first; iter != iterp.second; iter++) {
		if (*iter == drawer) {
			mDrawers.erase(iter);
			break;
		}
	}
}

SDL_Texture* Game::GetTexture(const std::string& fileName) {
	SDL_Texture* tex = nullptr;
	auto iter = mTextures.find(fileName);
	if (iter != mTextures.end()) {
		tex = iter->second;
	}
	else {
		SDL_Surface* surf = IMG_Load(fileName.c_str());
		if (!surf) {
			SDL_Log("Failed to load texture file : %s", fileName.c_str());
			return nullptr;
		}

		tex = SDL_CreateTextureFromSurface(mRenderer, surf);
		SDL_FreeSurface(surf);
		if (!tex)
		{
			SDL_Log("Failed to convert surface to texture for %s", fileName.c_str());
			return nullptr;
		}

		mTextures.emplace(fileName.c_str(), tex);
	}
	return tex;
}